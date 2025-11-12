#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll m,n,cnt=0;
	cin>>m>>n;
	string s;
	cin>>s;
	int f[505];
	for(int i=1;i<=n;i++)
	{cin>>f[i];}
	if(m==n)
	{
		ll sum=1;
		for(int i=2;i<=n;i++){
			sum%=mod;
			sum*=i;
		}
		cout<<sum;
	}
	else{
		for(int i=1;i<=n;i++)
		{
			
			{
				if(f[i]<=0)
				{
					for(int j=i+1;j<=n;j++){
					f[j]--;
					cout<<f[j]<<" ";
				    }
					
					cnt++;
				}
			}
		}
		n-=cnt;
		cout<<n;
		if(n<m)cout<<"0";
		else{
			ll sum=1;
		    for(int i=2;i<=n;i++){
			sum%=mod;
			sum*=i;
		    }
		    cout<<sum;
		}
	}
	return 0;
}
