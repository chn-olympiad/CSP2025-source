#include <bits/stdc++.h>
using namespace std;
int n,m;
struct k{
	int sc,nu,snx,sny;
}a[10005];
bool cmp(k x,k y){
	return x.sc>y.sc;
}
bool cmp1(k x,k y){
	return x.nu<y.nu;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].nu=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(i%n==0){
			a[i].snx=i/n;
		}else{
			a[i].snx=i/n+1;
		}
		if(a[i].snx%2==0){
			if(i%n==0){
				a[i].sny=1;
			}else{
				a[i].sny=n-i%n+1;
			} 
		}else{
			if(i%n==0){
				a[i].sny=n;
			}else{
				a[i].sny=i%n;
			}
		}
	}
	sort(a+1,a+n*m+1,cmp1);
	cout<<a[1].snx<<" "<<a[1].sny;
	return 0;
}
