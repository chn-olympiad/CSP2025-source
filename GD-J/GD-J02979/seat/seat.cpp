#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=105;
ll n,m,a[N],R,tot;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m; tot=n*m;
	for(int i=1;i<=tot;i++){
		cin>>a[i];
		if(i==1) R=a[i];
	}sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--)
		if(R==a[i]){
			R=tot-i+1;
			break;
		} 
	ll l=(R-1)/n+1;
	if(l&1) cout<<l<<' '<<(R-1)%n+1;
	else cout<<l<<' '<<n-((R-1)%n+1)+1;
	return 0;
}
