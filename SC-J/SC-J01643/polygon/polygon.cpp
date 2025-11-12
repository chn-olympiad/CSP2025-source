#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[100000],k=0,b=0,n,l=0,h=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=1;j<=n;j++){
		    if(i==3){
		    	if(a[j]+a[j+1]>a[j+2]){
				
		        l++;
		    }
			}
			else{
				for(int u=1;u<=i;u++){
					h=h*u;
				}
				for(int t=1;t<=n;t++){
				k=	t*k;
				}
				l=l+k/h;
			}
		}
	}

	cout<<l;
    
	return 0;
}