#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
struct data{
	int id,s;
}a[105];
bool cmp(data x,data y){
	return x.s>y.s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			if(i%m==0){
				c=i/m;
			}else{
				c=i/m+1;
			}
			if(c%2==1){
				if(i%n==0){
					r=n;
				}else{
					r=i%n;
				}
			}else{
				if(i%n==0){
					r=1;
				}else{
					r=n-i%n+1;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
} 
