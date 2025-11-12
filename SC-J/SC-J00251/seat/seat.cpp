#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1; cin>>n>>m;
	cin>>a1; a[1]=a1;
	for(int i=2;i<=n*m;++i){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int rk=1;
	for(;rk<=n*m;++rk){
		if(a[rk]==a1) break;
	}rk=n*m-rk+1;
	int lin=(rk-1)/n+1,rw;
	if(lin&1){
		rw=(rk%n)?(rk%n):(n); 
	}
	else{
		rw=(rk%n)?(rk%n):(n); 
		rw=n-rw+1;
	}
	cout<<lin<<' '<<rw;
	return 0;
}