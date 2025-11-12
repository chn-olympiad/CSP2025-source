#include<bits/stdc++.h>
using namespace std;
int n;
int arr[50005];
long long fin(int maxn,int all,int k){
	long long ans = 0;
	if(maxn*2 < all && k > n)	return 1;
	else if(k > n)	return 0;
	ans += fin((maxn < arr[k] ? arr[k] : maxn),all+arr[k],k+1);
	ans += fin(maxn,all,k+1);
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		scanf("%d",&arr[i]);
	printf("%lld",fin(0,0,1) % 998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
