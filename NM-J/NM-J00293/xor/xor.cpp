#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],dp[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int i=1;i<=n;i++){
		int kk=0;
		for(int j=i;j<=n;j++){
			//if(j==k||)
		}
		dp[i]=max(dp[i-1],kk);
	}
	return 0;
}
