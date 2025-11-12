#include<bits/stdc++.h> 
using namespace std;
long long a[10001];
int c,r;

int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++){
		cin>>a[i];
	}
	for(long long j=1;j<=n*m;j++){
		for(long long k=1;k+j<=n*m;k++){
			if(a[j]<a[j+k]){
				a[j]=a[j+k];
			    a[j+k]=a[j];
			    
			}else{
				break;
			}
		}
		if(j<=n){
			c=1;
			r=j+1;
		}else{
			for(long long l=2;l<=m;l++){
					if(l%2==0){
		            c=l;
		            r=l*n-j+2;
		            }else{
			           c=l;
			          r=l*n-j+1;
		           }
		 	   }
	     	}
		}
	cout<<c<<" "<<r;
	return 0;
}