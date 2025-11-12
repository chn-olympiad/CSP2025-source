#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000000;
#define ll long long
long long t,p,m,ans,n;
long long ta,tb,tc,tmp,temp;
long long club[MAXN][3];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(ll i=1;i<=t;i++)
	{
		ans=0;
		cin>>p;ll h=p/2;
		for(ll j=1;j<=p;j++)
		{ 
			for(ll z=1;z<=3;z++)
			{
				cin>>club[j][z];
			}
		}
		for(ll n=1;n<=p;n++)
		{
			tmp=max(club[n][1],club[n][2]);
			temp=max(club[n][2],club[n][3]);
			ans+=max(tmp,temp);
		}
		cout<<ans<<endl;
	}
	return 0;
}
