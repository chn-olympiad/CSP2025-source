#include<bits/stdc++.h>
using namespace std;
long long n,q,wz[200010][2];
vector <long long> jump[200010];
string s[200010][2],t[2];
map <long long,vector <long long> > mp;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	bool flag=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		wz[i][0]=-1;
		wz[i][1]=-1;
		long long now=-1;
		for(long long j=0;j<s[i][0].size();j++)
		{
			if((s[i][0][j]!='a'&&s[i][0][j]!='b')||(s[i][1][j]!='a'&&s[i][1][j]!='b')) flag=0;
			if(s[i][0][j]=='b')
			{
				if(wz[i][0]!=-1) flag=0;
				wz[i][0]=j;
			}
			if(s[i][1][j]=='b')
			{
				if(wz[i][1]!=-1) flag=0;
				wz[i][1]=j;
			}
			if(j==0)
			{
				jump[i].emplace_back(-1);
				continue;
			}
			while(s[i][0][now+1]!=s[i][0][j]||s[i][1][now+1]!=s[i][1][j])
			{
				if(now==-1)
				{
					now--;
					break;
				}
				now=jump[i][now];
			}
			now++;
			jump[i].emplace_back(now);
		}
		if(flag)
		{
			if(wz[i][0]==-1)
			{
				flag=0;
				continue;
			}
			if(wz[i][1]==-1)
			{
				flag=0;
				continue;
			}
			mp[wz[i][0]-wz[i][1]].emplace_back(i);
		}
	}
	while(q--)
	{
		long long ans=0,now=-1,t0=-1,t1=-1;
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size())
		{
			puts("0");
			continue;
		}
		if(flag)
		{
			for(long long j=0;j<t[0].size();j++)
			{
				if((t[0][j]!='a'&&t[0][j]!='b')||(t[1][j]!='a'&&t[1][j]!='b'))
				{
					flag=0;
					break;
				}
				if(t[0][j]=='b')
				{
					if(t0!=-1)
					{
						flag=0;
						break;
					}
					t0=j;
				}
				if(t[1][j]=='b')
				{
					if(t1!=-1)
					{
						flag=0;
						break;
					}
					t1=j;
				}
			}
			if(t0==-1||t1==-1) flag=0;
			if(flag)
			{
				for(long long at:mp[t0-t1])
				{
					if(s[at][0].size()>t[0].size()) continue;
					if(t0<wz[at][0]) continue;
					if(t0-wz[at][0]+s[at][0].size()>t[0].size()) continue;
					ans++;
				}
				printf("%lld\n",ans);
				continue;
			}
		}
		for(long long i=1;i<=n;i++)
		{
			if(s[i][0].size()>t[0].size())
			{
				continue;
			}
			long long gs=0;
			for(long long j=0;j<t[0].size();j++)
			{
				while(s[i][0][now+1]!=t[0][j]||s[i][1][now+1]!=t[1][j])
				{
					if(now==-1)
					{
						now--;
						break;
					}
					now=jump[i][now];
				}
				now++;
				if(now==s[i][0].size()-1)
				{
					ans++;
					gs++;
					if(gs>1)
					{
						ans-=2;
						break;
					}
					now=jump[i][now];
				}
			}
		}
		printf("%lld\n",ans);
	}
}
