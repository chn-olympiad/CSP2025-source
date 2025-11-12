#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],xm;
int b[105];
int c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
		
	}
	xm=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1;i<=n*m;i++){
		b[n*m-i+1]=a[i];
	}
	for(int i=1;i<=m*n;i++){
		cout<<b[i]<<" ";
	}
	for(int i=1;i<=m*n;i++){
		if(b[i]==xm){
			
			if(i%n==0){
				c=(i/n);
			}
			else c=(i/n)+1;
			if(c%2==0){
				r=n-(i-(c-1)*n)+1;
			}
			else r=i-(c-1)*n;
			cout<<c<<" "<<r<<endl;
			return 0;
		}
	}
}
