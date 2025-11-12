#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
int a[5005],b[5005];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	 cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
	 b[i]=a[i]+b[i-1];
	}
	for(int i=1;i<=n-2;i++){
	    for(int j=i+2;j<=n;j++){
	 	int x=b[j]-b[i-1];
	 	if(x>a[j]*2){
	 		sum++;
		 }
	 	} 
	}for(int i=n;i>2;i--){
	    for(int j=1;j<=i-3;j++){
	    	int x=b[i]+b[1];
		 for(int k=2;k<i;k++){
	    		if(x-b[k]>a[i]*2){
	    			sum++;
	    			x=b[i]+b[k-j+1];
				}
			}
	 	} 
	}
	cout<<sum%998244358;
}

