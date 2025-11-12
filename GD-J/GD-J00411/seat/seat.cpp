#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e2+10;
ll a[maxn][maxn],n,m,b[maxn*maxn];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++)cin>>b[i];
	ll me=b[1];
	sort(b+1,b+n*m+1,cmp);
	ll y=1;
	for(ll i=1;i<=m;i++){
		if(i%2==1){
			for(ll j=1;j<=n;j++){
				a[j][i]=b[y];
				y++;
			}
		}
		else{
			for(ll j=n;j>=1;j--){
				a[j][i]=b[y];
				y++;
			}
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			if(a[i][j]==me){
				cout<<j<<" "<<i;
				return 0;
			} 
		}
	}
	
	
	return 0;
}
