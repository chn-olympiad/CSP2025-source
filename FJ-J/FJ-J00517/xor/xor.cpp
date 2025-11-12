#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
int a[max_n],s[max_n],p[max_n],dp[max_n];
int n,k;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		s[i]=(s[i-1]^a[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			if((s[j]^s[i-1])==k){
				p[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;++i){
		int x=i,y=p[i],maxx=0;
		for(int j=1;j<=x-1;++j){
			maxx=max(maxx,dp[j]);
		}
		dp[y]=max(maxx+1,dp[y]);
	}
	
	int maxx=-1;
	for(int i=1;i<=n;++i){
		maxx=max(maxx,dp[i]);
	}
	cout << maxx;
	return 0;
} 
