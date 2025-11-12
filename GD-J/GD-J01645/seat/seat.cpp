#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e2+10;
ll n,m,k=1,a[N],ans[N][N];
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	ll len=n*m;
	for(ll i=1;i<=len;i++) cin>>a[i];
	ll anscj=a[1]; 
	sort(a+1,a+len+1,cmp);
	for(ll i=1;i<=m;i++){
		if(i%2==0) for(ll j=n;j>=1;j--,k++) ans[i][j]=a[k];
		else for(ll j=1;j<=n;j++,k++) ans[i][j]=a[k];
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=n;j++){
			if(ans[i][j]==anscj) cout<<i<<" "<<j;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
