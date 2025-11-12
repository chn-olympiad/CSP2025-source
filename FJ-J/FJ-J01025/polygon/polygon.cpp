#include<bits/stdc++.h>
using namespace std;
int n,a[5010],ans;
inline int pow2(int x) {
	int p=1;
	for(int i=1; i<=x; i++) {
		p=p*2%998244353;
	}
	return p;
}
inline int dfs(int sum,int x){
	if(x>n)return 0;
	for(int i=x;i<=n;i++){
		if(sum==a[i]){
			return 1;
		}
	}
	return dfs(sum+a[x],x+1)+dfs(sum,x+1);
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	if(n<=10) {
		sort(a+1,a+n+1);
		for(int i=1; i<=n-2; i++) {
			for(int j=i+1; j<=n-1; j++) {
				for(int k=j+1; k<=n; k++) {
					if(a[i]+a[j]>a[k]) {
						ans=ans+pow2(i-1);
					}
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			int m=dfs(0,i);
			if(m){
				ans+=(pow2(i-1)-1)*m;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=1){
			return 0;
		}
	}
	int m=pow2(n)-n-n*(n-1)/2;
	if(m<0)m+=998244353;
	cout<<m;
	return 0;
}
