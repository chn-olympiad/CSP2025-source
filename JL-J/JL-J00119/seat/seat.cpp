#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1010],a1;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	int p;
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++){
		if(a[i]==a1){
			p=i;
		}
	}
	if(p%(2*n)<=n){
		cout<<(p-1)/n+1<<' '<<p%(2*n);
	}else{
		cout<<(p-1)/n+1<<' '<<n-(p%n)+1;
	}
	return 0;
}
