#include <bits/stdc++.h>
using namespace std;
int n,m,c,r;
struct node{
	int t,id;
}a[105];
bool cmp(node x,node y){
	return x.t>y.t;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].t; 
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			c=(i-1)/n+1;
			if(c%2==0){
				if(i%n==0){
					r=1;
				}
				else{
					r=n-i%n+1;
				}
			}
			else{
				if(i%n==0){
					r=n;
				}
				else{
					r=i%n;
				}
			}
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
