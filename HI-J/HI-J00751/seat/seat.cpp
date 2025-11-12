#include<bits/stdc++.h>
using namespace std;
int b[15][15],n,m,a[105],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i]; 
	} 
	sort(a,a+(n*m));
	if(r<a[1]) cout<<n<<" "<<m;
	if(r>a[n*m-1]) cout<<1<<" "<<1;
	
	return 0;
}
