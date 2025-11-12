#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
inline int read()
{
	int num=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') num=num*10+c-'0',c=getchar();
	return num*f;
}
void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10),x%=10;
	putchar(x+'0');
}
int n,q,l[N],id1[N],id2[N],p1,p2,ans;
pair<string,string>s[N],t;
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) 
	{
		cin>>s[i].first>>s[i].second;
		l[i]=s[i].first.size();
		for(int j=0;j<l[i];j++)
		{
			if(s[i].first[j]=='b') id1[i]=j;
			if(s[i].second[j]=='b') id2[i]=j;
		}
	}
	while(q--)
	{
		cin>>t.first>>t.second;
		if(t.first.size()!=t.second.size()) printf("0\n");
		else
		{
			l[n+1]=t.first.size(),p1=p2=ans=0;
			for(int i=0;i<l[n+1];i++)
			{
				if(t.first[i]=='b') p1=i;
				if(t.second[i]=='b') p2=i;
			}
			for(int i=1;i<=n;i++)
			{
				if(id1[i]<=p1&&l[i]-id1[i]<=l[n+1]-p2&&id2[i]-id1[i]==p2-p1) ans++;
			}
		}
		write(ans),putchar('\n');
	}
	return 0;
}
