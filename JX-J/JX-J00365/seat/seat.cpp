#include <bits/stdc++.h>
using namespace std;
int n,m,i,c,r,p;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
	    cin>>a[i];
	    if(i==1){
		    p=a[i];    
		}    
	}
	sort(a,a+i);
	for(i=n*m;i>=1;i--){
	    if(a[i]==p){
		    if((n*m-i+1)%m!=0){
			    c=(n*m-i+1)/m+1;
			    if(c%2==0){
				    r=m-((n*m-i+1)%m)+1;
				}else{
				    r=(n*m-i+1)%m;
				} 
			}else{
			    c=(n*m-i+1)/m;
			    if(c%2==0){
				    r=1;
				}else{
				    r=m;
				}  
			}
			break;    
		}
	}
	cout<<c<<r;
	return 0;
}
