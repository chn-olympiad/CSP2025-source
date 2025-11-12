#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n],sum1=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(long long i=3;i<=n;i++){
		for(long long j=i-1;j<n;j++){
			long long sum=0,max1=0;
			for(long long k=j-i+1;k<=j;k++){
				sum+=a[k];
				if(k!=j-1) max1=max(a[k],a[k+1]);
			}if(sum>max1*2){
				sum1++;
				for(long long k=j-i+1;k<=j;k++){
					cout<<a[k]<<" ";
				}cout<<endl;
			}
		}
	}cout<<sum1;
	return 0;
}
