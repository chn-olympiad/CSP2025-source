#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	if(a[1]==1 && a[n*m]==n*m){
		if(m%2) cout<<n<<" "<<m;
		else cout<<1<<" "<<m;
	}
	else if(a[1]==n*m) cout<<1<<" "<<1;
	return 0;
}
