#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<vector<ll>> a(n+1,vector<ll>(3));
		vector<vector<ll>> b(n+1,vector<ll>(3));
		vector<vector<ll>> c(n+1,vector<ll>(3));
		for(ll i=0;i<n;i++){
			for(ll j=0;j<3;j++){
				cin>>a[i][j];
				b[i][j]=a[i][j];
			}
			sort(b[i].begin(),b[i].end());
		}
		if(n==2){
			ll m=0;
			for(ll i=0;i<n;i++){
				for(ll j=0;j<n;j++){
//					cout<<a[0][i]+a[1][j]<<endl;
					if(a[0][i]+a[1][j]>m&&i!=j) 
						m=a[0][i]+a[1][j];
				}
			}
			cout<<m<<endl;
		}
//		cout<<endl;
		else{
			ll a1=0,b1=0,c1=0,sum=0,f1=0;
			vector<ll> a2(n+1);
			bool f=0;
			for(ll i=0;i<n;i++){
				if(a[i][0]==0&&a[i][2]==0){
					f=1;
					a2[f1]=a[i][1];
					f1++;
				}else{
					f=0;
					break;
				}
			}
			for(ll i=0;i<n;i++){
				if(a[i][1]==0&&a[i][2]==0){
					f=1;
					a2[f1]=a[i][0];
					f1++;
				}else{
					f=0;
					break;
				}
			}
			for(ll i=0;i<n;i++){
				if(a[i][0]==0&&a[i][1]==0){
					f=1;
					a2[f1]=a[i][2];
					f1++;
				}else{
					f=0;
					break;
				}
			}
			sort(a2.begin(),a2.end());
			if(f) cout<<a2[n]+a2[n-1]<<endl;
			if(!f){
				for(ll i=0;i<n;i++){
					for(ll j=0;j<3;j++){
//						cout<<b[i][j]<<' ';
					}
//					cout<<endl;
				}
//				cout<<endl;
				for(ll i=0;i<n;i++){
					for(ll j=0;j<3;j++){
						for(ll k=0;k<3;k++){
							if(b[i][j]==a[i][k]){
								c[i][j]=k;
//								cout<<k<<' ';
								break;
							}
						}	
					}
//					cout<<endl;
				}
				for(ll i=0;i<n;i++){
					if(c[i][2]==0) a1++;
					if(c[i][2]==1) b1++;
					if(c[i][2]==2) c1++;
					sum+=b[i][2];	
				}
				if(a1<=n/2&&b1<=n/2&&c1<=n/2){
					cout<<sum<<endl;
				}
			}
		}
	}
	return 0;
}

