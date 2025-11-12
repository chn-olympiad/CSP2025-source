#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
int ans=0;
int x[5005];
map<int,int> t;
int sxo[5005];
vector<pair<int,int>> ste;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i],t[x[i]]++,sxo[i]=sxo[i-1]^x[i];
	if(k==0)
	{
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				bool flag=1;
				for(auto tt:ste)
				{
					if(tt.second>=i)
					{
						flag=0;
						break;
					}
				}
				if(flag==0)
					break;
				if((sxo[j]^sxo[i-1])==0)
					ans++,ste.push_back(make_pair(i,j));
			}
		cout<<ans<<"\n";
		return 0;
	}
	if(k==1)
	{
		if(t[0]==0 || t[1]==0)
			cout<<0;
		cout<<max(t[1],t[0])<<"\n";
		return 0;
	}
	
	return 0;
}
/*
Luogu id=1383031
*/
