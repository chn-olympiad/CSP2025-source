#include<bits/stdc++.h>
using namespace std;
int t,n,a[3][100001],dp[100001],lena,lenb,lenc; 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
			if((lena+1)<=(n/2)) dp[i]=dp[i-1]+a[0][i];
			else if((lenb+1)<=(n/2)) dp[i]=max(dp[i],dp[i-1]+a[1][i]);
			else if((lenc+1)<=(n/2)) dp[i]=max(dp[i],dp[i-1]+a[2][i]);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],dp[100001],b; 

int main(){///*
	freopen("club5.in","r",stdin);
	freopen("club5.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			scanf("%d",&b);
		}
		sort(a+1,a+n+1);
		b=0;
		for(int i=n;i>=n/2;i--){
			b+=a[i];
		}
		printf("%d\n",b);
	}
	return 0;
}

*/
