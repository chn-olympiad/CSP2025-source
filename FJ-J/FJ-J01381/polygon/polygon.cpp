#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum=0,cnt=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		cnt=1;
		for(int j=n;j>=n-i+1;j--){
			cnt*=j;
		}
		for(int k=1;k<=i;k++){
			cnt/=k;
		}
		sum+=cnt;
	}
	cout<<sum;
	
	return 0;
} 
