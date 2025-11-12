#include<bits/stdc++.h>
using namespace std;
using ll=int;
ll t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ll n,a[100005][4],b[4]={0,0,0,0},ans=0,z,c;
		cin>>n;z=n/2;
		for(ll i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}for(ll i=1;i<=n;i++){
			ll x=0;
			for(ll j=1;j<=3;j++){
				if(a[i][j]>=x&&b[j]<z){x=a[i][j];c=j;}
			}ans+=x;b[c]++;
		}cout<<ans<<endl;
	}
	return 0;
}
