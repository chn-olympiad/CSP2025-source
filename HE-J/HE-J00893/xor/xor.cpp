#include<bits/stdc++.h>
using namespace std;
int f[1001];
int sum[1001][1001];
int a[1001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)cnt++;
	}
	if(cnt==n){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		sum[1][i]=sum[1][i-1]^a[i];
		sum[i][1]=sum[i-1][1]^a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(i==j)sum[i][j]=a[i];
			else sum[i][j]=sum[i][j-1]^a[j];
		}
	}
	if(a[1]==k)f[1]=1;
	for(int i=2;i<=n;i++){
		if(sum[1][i]==k){
			f[i]=1;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			int mid=sum[j+1][i];
			if(mid==k){
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	cout<<f[n];
	return 0;
}

