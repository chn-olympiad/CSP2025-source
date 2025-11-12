#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000005];
long long sum1=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		int m=0;
		int sum=0;
		for(int k=1;k<=n-i;k++){
			for(int j=k;j<=i+k;j++){
			    if(a[j]>m){
				    m=a[j];
			    }
			    sum+=a[j];
		    }
		    if(sum>m*2){
			    sum1++;
		    }
		}
		
	}
	cout<<sum1;
	return 0;
} 
