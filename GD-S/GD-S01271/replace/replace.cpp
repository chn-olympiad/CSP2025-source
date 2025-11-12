#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int n,q;
string sa[N];
string sb[N];
string t1;
string t2;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=in(),q=in();
	for(int i=1;i<=n;i++)
	{
		cin>>sa[i];
		cin>>sb[i];
	}
	while(q--)
	{
		cin>>t1;
		cin>>t2;
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			int l=sa[j].length();
			string tmp="";
			for(int i=0;i<t1.length()-l+1;i++)
			{
				string tt=t1.substr(i,l);
				if(tt==sa[j])
				{
					string tm=t1.substr(0,i);
					string tp=t1.substr(i+l,t1.length()-i-l);
					tmp=tm+sb[j]+tp;
					if(tmp==t2)
					{
						cnt++;
					} 
				}
				
			}
		}
		out(cnt);
		puts("");
	}
	return 0;
}

