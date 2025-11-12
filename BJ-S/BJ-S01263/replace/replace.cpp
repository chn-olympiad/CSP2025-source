#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
string s[N][3];
int su[M];
bool v[M];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	while(m--)
	{
		int cntt=0,ans=0;
		string t,tt;
		cin>>t>>tt;
		int len=t.size();
		for(int i=0;i<len;i++)
			v[i]=su[i]=0;
		for(int i=0;i<len;i++)
			if(t[i]!=tt[i])
				v[i]=1,cntt++;
		su[0]=v[0];
		for(int i=1;i<=len;i++)
			su[i]=su[i-1]+v[i];
		for(int i=1;i<=n;i++)//s[i]
		{
			for(int j=0;j+s[i][0].size()-1<len;j++)
			{
				if(j==0&&su[j+s[i][0].size()-1]<cntt)
					continue;
				if(j!=0&&su[j+s[i][0].size()-1]-su[j-1]<cntt)
					continue;
				bool f=0;
				for(int k=j;k<=j+s[i][0].size()-1;k++)
					if(s[i][0][k-j]!=t[k])
					{
						f=1;
						break;
					}
				if(!f)
				{
					f=0;
					int cnt=0;
					for(int k=j;k<=j+s[i][1].size()-1;k++)
					{
						if(s[i][1][k-j]==tt[k]&&v[k])
							cnt++;
						if(s[i][1][k-j]!=tt[k])
						{
							f=1;
							break;
						}
					}
					if(!f)
						ans+=(cntt==cnt);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
