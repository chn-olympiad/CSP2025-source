#include<bits/stdc++.h>
using namespace std;
int read(){
	int x,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x*=10;
		x+=c-'0';
		c=getchar();
	}
	return f*x;
}
int n,a[500005],b[500005],ans,k,dp[10005][10005],d[10005],l[500005],r[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	if(k==0){
		cout<<"1\n";
		return 0;
	}
	//cout<<b[0]<<' ';
	for(int i=0;i<n;i++){
	//	cout<<b[i+1]<<' ';
		for(int j=i+1;j<=n;j++){
			if((b[j]^b[i])==k){
				ans++;
				//cout<<b[j]<<'^'<<b[i]<<'='<<(b[j]^b[i])<<'\n';
				l[ans]=i+1;
				r[ans]=j;
				
			}
		}
	}
	for(int i=1;i<=ans;i++){ 
		for(int j=1;j<=n;j++){
			for(int k=n;k>=j;k--){
				if(j<=l[i]&&k>=r[i]){				
					dp[j][k]=max(dp[j][k],dp[j][l[i]-1]+dp[r[i]+1][k]+1);
				}
			}
		}
	}
	cout<<dp[1][n]<<'\n';
	/*
	100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

	*/
	return 0;
}

