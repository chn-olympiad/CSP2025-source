#include<bits/stdc++.h>
#define N 105
using namespace std;
int n,m,a[N],r,rk;
inline bool cmp(int x,int y){return x>y;}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>r;rk=n*m;
	for(int i=1;i<n*m;i++) cin>>a[i];
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<n*m;i++){
		if(r>=a[i]){rk=i;break;}
	} 
	int x=(rk-1)/n+1;
	cout<<x<<' ';
	if(x&1) cout<<(rk-1)%n+1;
	else cout<<n-(rk-1)%n;
	return 0;
}
