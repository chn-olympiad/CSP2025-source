#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 200000;
int n,T,len[N+10],ln,ans,l,r,exans;

string s[N+10][2],t[2];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin>>n>>T;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s[i][0]>>s[i][1];
		len[i] = s[i][0].size();
	}
	
	while(T--)
	{
		cin>>t[0]>>t[1];
		ans = 0;
		
		if(t[0].size() != t[1].size())
		{
			cout<<0<<"\n";
			continue;
		}
		
		ln = t[0].size();
		
		l = -1 , r = -1;
		for(int i=0;i<ln;i++)
		{
			if(t[0][i] != t[1][i])
			{
				r = i;
				if(l==-1)
					l = i;
			}
		}
		if(l==-1)
			l = n-1 , r = 0;
		
		for(int i=0;i<=l;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if( i+len[j] > ln || i+len[j] <= r )
					continue;
				int f = 1;
				for(int k=0 ; k<len[j] ; k++)
				{
					if(t[0][i+k] != s[j][0][k] || t[1][i+k] != s[j][1][k])
					{
						f=0;
						break;
					}
				}
				if(f)
					ans++;
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
} 
