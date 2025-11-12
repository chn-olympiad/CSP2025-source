#include<bits/stdc++.h>
using namespace std;
int n,m,f,c,r;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			i=m*n-i+1;
			if(i%m==0){
				c=i/m;
			}else{
				c=i/m+1;
			}
			if(!(c%2)){
				if(i%n){
					r=i%n;
				}else{
					r=n; 
				}
			}else{
				if(i%n){
					r=n-i%n;
				}else{
					r=1;
				}
			}
			cout<<c<<' '<<r;
			return 0;
		}
	}
}
