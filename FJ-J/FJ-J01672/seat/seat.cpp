#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,x;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1]; 
	int fz=2*n;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			if(m==1){
				cout<<i<<" "<<m;
				return 0;
			}
			c=i/fz*2+1;
			r=i%fz;
			if(r==0){
				c--;
				r=fz;
			}
			if(r>n){
				c++;
				r=fz-r+1;
			}
			cout<<c<<" "<<r;
			return 0;
		} 
	}
	return 0;
}

