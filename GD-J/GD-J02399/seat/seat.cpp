#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],id[105];
int main(){
	freopen("seat.in","r",stdin),freopen("seat.out","w",stdout);
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i],id[i]=i;
	sort(id+1,id+1+n*m,[](int x,int y){return a[x]>a[y];});
	for(int i=1;i<=n*m;i++)if(id[i]==1)cout<<(i-1)/n+1<<" "<<((i-1)/n&1?m+1+(i-1)/n*n-i:i-(i-1)/n*n);
	return 0;
}
