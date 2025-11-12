#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[15][15];
ll b[200];
bool cmp(const ll &x,const ll &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);        
	ll n,m,o=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		if(i%2!=0){
			for(ll j=1;j<=m;j++){
				o++;
				a[i][j]=o;
			}
		}
		else{
			for(ll j=m;j>=1;j--){
				o++; 
				a[i][j]=o;
			}
		}
	}
	ll s;
	cin>>s;
	for(ll i=2;i<=n*m;i++) cin>>b[i];
	b[1]=s;
	sort(b+1,b+1+m*n,cmp);
	for(ll i=1;i<=n*m;i++) if(s==b[i]) s=i;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(a[i][j]==s) cout<<i<<" "<<j;
		}
	}
	
	return 0;
}
