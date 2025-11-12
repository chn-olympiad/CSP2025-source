#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i<=n*m;i++) scanf("%d",&a[i]);
	r = a[1];
	sort(a+1,a+1+n*m);
	int ans;
	for(int i = n*m;i>=1;i--){
		if(a[i] == r) {
			ans = n*m-i+1;
		}
	}
	int l,p;
	if(ans%(2*n) < n){
		l = ans/n+1;
		p = ans%n;
	}
	else if (ans%(2*n) == n){
		l = ans/n;
		p = n;
	}
	else{
		l = ans/n+1;
		p = n-ans%n+1;
	}
	cout<<l<<" "<<p;
}
