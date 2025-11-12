#include<bits/stdc++.h>
using namespace std;
int n,m;
struct seat{
	int b,f;
}a[105];
bool px(seat x,seat y){
	return x.f>y.f;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].b=i;
	}
	sort(a+1,a+n*m+1,px);
	for(int i=1;i<=n*m;i++){
		if(a[i].b==1){
			int ans=(i-1)/n+1;
			cout<<ans<<" ";
			if(ans%2==1) cout<<i-(ans-1)*n;
			else cout<<n-(i-(ans-1)*n)+1;
			return 0;
		}
	}
	return 0;
}
