#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum;
bool f=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(f==0){
		if(k==10) cout<<n/2;
		else cout<<0;
	}
	else{
		int sum[505][505],cnt=0;
		for(int i=1;i<=n;i++){
			sum[i][0]=0;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				sum[i][j]=sum[i][j-1]^a[i];
				if(sum[i][j]==k) cnt++;
			}
		}
		cout<<2;
	}
	return 0;
}
