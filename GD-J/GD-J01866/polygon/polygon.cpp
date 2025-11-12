#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int a[N+5],sum[N+5];
int qiu(int l,int r){
	return sum[r]-sum[l-1];
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(qiu(i,j)>2*a[j]){
				for(int k=i;k<=j;k++)cout<<a[k]<<" ";
				cout<<'\n';
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

