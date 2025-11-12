#include <bits/stdc++.h>
using namespace std;
int n,m,i;
struct po{
	int num; int id;
}a[1145];
int cmp(po x,po y){
	return x.num>y.num;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for( i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+m*n+1,cmp);
	for(i=1;i<=n*m;i++){
		if(a[i].id==1){
			int d,h;
			if(i%n==0){
				d=n;
			}else{
				d=i%n;
			}
			h=i/n+1;
			if(i%n==0){
				h--;
			}
			if(h%2!=0){
				cout<<h<<" "<<d;
			}else{
				cout<<h<<" "<<n-d+1;
			}
			return 0;
		}
	}
	return 0;
} 
