#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	bool s;
}a[10000];
bool g(node x,node y){
	return x.x>y.x;
}
long long m,n,r,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;                   
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
	}
	a[1].s=1;
	sort(a+1,a+n*m+1,g);
	for(int i=1;i<=n*m;i++){
		if(a[i].s==1){
			c=(i+n-1)/n;
			int z=i-(c-1)*n;
			if(c%2==1){
				r=i%(z+1);
			}
			else if(c%2==0){
				r=n-i%n+1;
			}
		}
	}	
	cout<<c<<" "<<r;
	return 0;
}
