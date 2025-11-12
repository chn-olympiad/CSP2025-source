#include<bits/stdc++.h>
using namespace std;
long long n,a[54088],z,c=0,m=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int e=i+1;e<n;e++){
			if(a[e]<a[i]){
				z=a[i];
				a[i]=a[e];
				a[e]=z;
			}
		}
	}
	for(int i=0;i<n-2;i++){
		c=a[i]+c;
		for(int e=i+1;e<n-1;e++){
			z=a[i]+a[e];
			for(int j=e+1;j<n;j++){
				if(z+a[j]>a[j]*2){
					m++;
				}
			}
	    }
	    if(n>3){
	    	for(int e=i+1;e<n-1;e++){
		    	z=c+a[e];m-=1;
			    for(int j=e+1;j<n;j++){
				    if(z+a[j]>a[j]*2){
				    	m++;
				   }
			    }
	        }
		}
	}
	cout<<m;
	return 0;
}
