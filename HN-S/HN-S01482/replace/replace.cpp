#include<bits/stdc++.h>
#define ll long long
#define N 200002
using namespace std;
inline int in()
{
	int s=0,w=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')w=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';c=getchar();
	}return s*w;
}

int n,q,ans;
string s[N][3],t1,t2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in();q=in();
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][1]>>s[i][2];
	}
	while(q--)
	{
		ans=0;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++)
		{
			if(t1.find(s[i][1])!=-1)
			{
				int op=t1.find(s[i][1]);
				string x=t1.substr(0,op),y=s[i][2],z=t1.substr(op+s[i][1].size(),t1.size()-s[i][1].size()-op);
				if(x+y+z==t2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

