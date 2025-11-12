#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=105;
int n,m;
int a[N],o;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(rint i=1;i<=n*m;++i) cin>>a[i];
	o=a[1],sort(a+1,a+1+n*m,greater<int>());
	for(rint i=1;i<=n*m;++i) if(o==a[i]){ o=i; break;}
	for(rint i=1;i<=m;++i){
		if(i*n<o) continue;
		cout<<i<<' ';
		o-=(i-1)*n;
		if(i&1) cout<<o;
		else cout<<n-o+1;
		break;
	}
	return 0;
}
