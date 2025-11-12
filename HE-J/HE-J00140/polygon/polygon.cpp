#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int max1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>max1){
			max1=a[i];
		}
	}
	if(sum>2*max1){
		if(n==3){
			cout<<1;
		}else{
			cout<<2*n-1;
		}
	}
	return 0;
}
