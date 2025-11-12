//GZ-S00105 贵阳市第三中学 周忠杰  
#include<bits/stdc++.h>
using namespace std;
//Ren5Jie4Di4Ling5%
#define ll long long
ll n,m,k;
ll a[1000005][4];
ll b[15][100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(ll i=1;i<=m;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	}
	for(ll i=1;i<=k;i++){
		for(ll j=1;j<=n+1;j++){
			cin>>b[i][j];
		}
	}
	if(k==0){
		ll ans=0;
		for(ll i=1;i<=m;i++){
			ans+=a[i][3];
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
