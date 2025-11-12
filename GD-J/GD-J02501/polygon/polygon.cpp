#include<bits/stdc++.h>
int n;
int stick[5001];
long long ans;
const int mod=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&stick[i]);
	ans%=mod;
	printf("%d",ans);
	return 0;
} 
