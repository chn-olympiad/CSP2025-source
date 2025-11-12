#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a,sum=1;
	cin>>a;
	for(int x=0;x<n*m-1;x++){
		int b;
		cin>>b;
		if(b>a)sum++;
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=i*n-n+1;j<=i*n;j++){
				if(j==sum)cout<<i<<" "<<sum-n*(i-1);
			}
		}
		else{
			for(int j=i*n;j>i*n-n;j--){
				if(j==sum)cout<<i<<" "<<n*i-sum+1;
			}
		}
	}
	return 0;
}