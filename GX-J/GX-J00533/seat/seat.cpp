#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c1,c2=0,b,d;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	c1=a[1];
	for(int i=1;i<=m*n;i++){
		if(i!=m*n){
			if(a[i]<a[i+1]){
				b=a[i];
				a[i]=a[i+1];
				a[i+1]=b;
			}
		}
	}
	for(int i=1;i<=m*n;i++){
		if(a[i]==c1){
			c1=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				c2++;
				if(c2==c1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}else{
			for(int j=n;j>=1;j--){
				c2++;
				if(c2==c1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}
