#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],b[101],x,y,n1,m1,n2,m2,n3;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    x=1;y=1,n1=0,m1=1,n2=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
	    cin>>b[i];	
	    if(i==1){
		    m2=b[i];	
		}
	}
	for(int i=n*m;i>=1;i--){
	    for(int j=1;j<=n*m;j++){
			if(b[j]<b[j+1]){
			    swap(b[j],b[j+1]);	
			}
		}	
	}
	if(n==1){
	    for(int i=1;i<=n*m;i++){
			if(b[i]==m2){
			    cout<<i<<" 1";
			    return 0;	
			}
		}
	}
		if(m==1){
			for(int i=1;i<=n*m;i++){
			if(b[i]==m2){
			    cout<<"1 "<<i;
			    return 0;	
			}
		}
		}
	while(n1!=n*m){
		n1++;
		a[x][y]=b[m1];
		if(b[m1]==m2){
			cout<<y<<' '<<x;
			return 0;
		}
		m1++;
		if(n2==1){
		    x++;
		    if(x==n){
			    n2=2;	
			}	
		}else{
		    if(n2==2){
			    y++;
			    if(x==n){
					n2=3;
				}else{
				    n2=1;	
				}	
			}else{
				if(n2==3){
					x--;
					if(x==1){
						n2=2;
					}
				}
			}	
		}
    } 
    return 0;
}
