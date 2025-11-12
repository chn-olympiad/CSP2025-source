#include<bits/stdc++.h>
using namespace std;
int n,k;
int p=998244353;
char m[507];
int a[507];
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%c",m[i]);		
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
//	for(int i=1;i<=n;i++){
//		scanf("%d",&a[i]);
//	}
	int ans=n;
	for(int i=1;i<n;i++){
		ans=ans*(n-i);
		ans=ans%p;
	}
	printf("%lld",ans);
	return 0;
}
