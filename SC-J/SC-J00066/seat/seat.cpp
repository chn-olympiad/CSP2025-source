#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
ll seat[N][N],sc[N];
ll n,m,k;

bool cmp(ll x,ll y) {return x>y;}
void printOut(){
	ll res=0,ret=0;
	if(k%n==0) ret=k/n;
	else ret=k/n+1;
	if(k%n==0) res=n;
	else res=k%n;
	if(ret%2==1) cout<<ret<<' '<<res;
	else cout<<ret<<' '<<n-res+1;
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>sc[i];
	k=sc[1];
	sort(sc+1,sc+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<sc[i]<<' '<<i<<'\n';
		if(sc[i]==k){
			k=i;
			break;
		}
	} 
	printOut();
	return 0;
}