#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
int a[N];
int k;
int b[N];
int dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j+=i){
			int smnt=0;
			for(int s=j-i;s<=j;s++){
				smnt=smnt|a[s];
			}
			if(smnt==k){
				b[j-i]++,b[j+1]--;
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+b[i];
		if(b[i]==-1&&dp[i-1]==1){
			maxx++;
		}
	}
	cout<<maxx;
	return 0;
}
