#include<bits/stdc++.h>
using namespace std; 
int n,k;
int a[500001];
int qh(int x,int y){
	int s=a[x];
	for(int i=x+1;i<=y;i++) s^=a[i];
	return s==k;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool dp[500001][500001];
	for(int i=1;i<=n;i++) 
		if(a[i]==k) dp[i][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=qh(i,j);
		}
	}
	int s=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(dp[i][j]){
				s++;
				i+=j;
			}
		}
	}
	cout<<s<<endl;
	return 0;
}
