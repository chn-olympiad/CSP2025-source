#include<bits/stdc++.h>
using namespace std;
int a[5005],ans=1,sum=1,k;
int xu(int n,int m){
	for(int i=n;i>=n+1-m;i--){
		ans*=i;
	}
	for(int j=1;j<=m;j++){
		sum*=j;
	}
	return ans/sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		k+=xu(n,i);
		ans=1,sum=1;
	}
	cout<<k;
	return 0;
}
