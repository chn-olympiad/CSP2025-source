#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,kk,a[N],dp[N][N];
struct node{
	int st,en;
}c[N];
bool cmp(node n1,node n2){
	return n1.st<n2.st?n1.st<n2.st:n1.en<n2.en;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>kk;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(kk==0){
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j&&a[i]==kk) dp[i][j]=kk;
			else{
				int sum=a[i];
				for(int k=i+1;k<=j;k++)
					sum=sum xor a[k];
				if(sum==kk)
					dp[i][j]=kk;
			}
		}
	}
	int we,cs=0,sum=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(dp[i][j]==kk)
				we=j;
				cs++;
				if(cs!=1){
					if(i>we){
						sum++;
						we=j; 
					} 
				}else
					sum=1;
		}
	cout<<sum;
	return 0;
}
