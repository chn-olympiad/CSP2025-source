#include<bits/stdc++.h>
using namespace std;
int c,r,n,m,b,a[110],d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			d=a[i];
		}
	}
	for(int i=1;i<=n*m;i++){
       for(int j=i+1;j<=n*m;j++){
          if(a[i]<a[j]){
             b=a[i];
             a[i]=a[j];
             a[j]=b;
          }
       }
    }
    for(int i=1;i<=n*m;i++){
    	if(a[i]==d){
    		d=i;
    		break;
		}
	}
	if(d<=n){
		cout<<1<<" "<<d;
		return 0;
	}else{
		r=d/n;
		if(d%n==0){
			if(r%2==0){
				cout<<r<<" "<<1;
				return 0;
			}else{
				cout<<r<<" "<<n;
				return 0;
			}
		}else{
			if(r%2==0){
				cout<<r+1<<" "<<d%n;
				return 0;
			}else{
				cout<<r+1<<" "<<r+1;
				return 0;
			}
		}
	}
}
