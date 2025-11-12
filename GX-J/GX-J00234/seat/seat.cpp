#include  <bits/stdc++.h>
using namespace std;

int n,m,c,r,a[105],big=1;


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
	cin>>a[i];
	if(i>1){
    if(a[i]>a[1]){
		big++;
		  }
       }	
    }
    
    
    for(int i=1;i<=m;i++){
		if(big<=i*n){
			c=i;
			if(i%2==0){
				r=n-(big-(i-1)*n)+1;
				}
				else{
				r=big-(i-1)*n;	
				}
			break;
			}
		}
    
    cout<<c<<" "<<r;
    
return 0;
}
