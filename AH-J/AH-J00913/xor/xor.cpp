#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100010],x[100010],dp[100010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int q=0;
		if(a[i]==k){
			x[i]=i;
			continue;
		}
		for(int j=i;j<=n;j++){
			q=q xor a[j];
			if(q==k){
				x[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<" "<<x[i]<<endl;
	}
	if(x[1]!=0)dp[1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(x[j]!=0&&x[j]<i)dp[i]=max(dp[i],dp[j]+1);
		}
	}
	printf("%d",dp[n]);
	return 0;
}

