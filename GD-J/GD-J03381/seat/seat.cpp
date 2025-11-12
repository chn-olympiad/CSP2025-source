#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,greater<>());
	for(int i=1;i<=n*m;++i){
		if(a[i]==k){
			int c=(i+n-1)/n,r=i-(c-1)*n;
			cout<<c<<' '<<(c&1?r:n-r+1)<<'\n';
		}
	}
}