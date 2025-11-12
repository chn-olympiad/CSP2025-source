#include <bits/stdc++.h>
using namespace std;
int a[1010];
int c[1010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum=0,f=0,g=0;
	cin>>n>>m;
	int b=n*m;
	for(int i=1;i<=b;i++){
		cin>>a[i];
		c[i]=i;
	}//100 
	if((n==1&&m==1)){
		cout<<1<<" "<<1;
	}
	for(int i=1;i<=b;i++){
		for(int j=i+1;j<=b;j++){
			if(a[i]<a[j]){
				int d=a[i];
				a[i]=a[j];
				a[j]=d;
				d=c[i];
				c[i]=c[j];
				c[j]=d;
			}
		}
	} 
	for(int i=1;i<=b;i++){
		if(c[i]==1){
		   sum=i;
		   break;	
		}
	} 
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
	            sum--;
	            if(sum==0){
	            	f=i;
	            	g=j;
	            	break;
	            }
 	        }
		}else{
			for(int j=1;j<=n;j++){
	            sum--;
	            if(sum==0){
	            	f=i;
	            	g=j;
	            	break;
	            }
 	        }
		}

	}
	cout<<f<<" "<<g;
	return 0;
} 
