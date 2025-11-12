#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
ll n,m,tot=0,dat[105],fl[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			tot++,cin>>dat[tot];
		}
	}
	ll rp=dat[1],rt=0;
	sort(dat+1,dat+n*m+1,greater<ll>());
	for(ll i=1;i<=m;i++){
		bool f=0; if(i&1) f=1;
		for(ll j=1;j<=n;j++){
			rt++;
			if(f){
				fl[j][i]=dat[rt];
			}else{
				fl[n-j+1][i]=dat[rt];
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=m;j++){
//			cout<<fl[i][j]<<" ";
//		}
//		cout<<endl;
//	} 
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(fl[i][j]==rp){
				cout<<j<<" "<<i<<endl;	
				break;
			}
		}
	} 
	return 0;
}
/*
2 2
98 99 100 97

*/

