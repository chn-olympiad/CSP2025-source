#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y,r;
bool cmp(int c,int d){
	return c>d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		if(r<=a[(i-1)*n+1] && r>=a[i*n]){
			x=i;
			for(int j=(i-1)*n+1;j<=i*n;j++){
				if(r==a[j]){
					if(i%2==1){
						y=(j-(i-1)*n);
					}else{
						y=i*n-j+1;
					}
					cout<<x<<" "<<y;
					return 0;
				}
			}
		}
	}
	
	return 0;
}
