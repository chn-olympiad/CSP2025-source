#include<bits/stdc++.h>
using namespace std;
int n,m,a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int sum=1;
	for(int i=1;i<n*m;i++){
		if(a[i]>a[0]){
			//cout<<a[i]<<' ';
			sum++;
		}
	}
	int k=sum/n;
	if(k*n==sum) cout<<k<<' ';
	else cout<<k+1<<' ';
	if(k*n==sum){
		if(k%2==1){
			cout<<n;
		}else cout<<1;
	}else{
		sum-=k*n;
		if(k%2==0) cout<<sum;
		else cout<<n-sum+1;
	}
}
