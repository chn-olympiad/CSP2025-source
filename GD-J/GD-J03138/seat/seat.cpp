#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=15;
int a[N*N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i]; 
	int c=a[1],pm;
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(c==a[i]) pm=i;
	}
	if(pm%n==0){
		cout<<pm/n<<" ";
	}else{
		cout<<pm/n+1<<" ";
	}
	if(pm%(2*n)<=n) cout<<pm%(2*n);
	else cout<<pm%(2*n)-1;
	return 0;
}
