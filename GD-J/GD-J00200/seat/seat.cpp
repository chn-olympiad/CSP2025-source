#include<bits/stdc++.h>
using namespace std;
double a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	double n,r;
	int x,m,c;cin>>n>>m;int y=n*m;
	for(int i=1;i<=y;i++){
		cin>>a[i];
		x=a[1]; 
	}
	sort(a+1,a+y+1);
	for(int i=y;i>=1;i--){
		if(a[i]==x){
			r=ceil(i/n);
			c=i/r;
		}
	}
	cout<<c<<' '<<r;
	return 0;
} 
