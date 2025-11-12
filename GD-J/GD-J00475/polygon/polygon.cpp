#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],mod=998244353,cnt;
bool f[5005][5005];
void dfs(long long maxn,long long len,long long sum,long long k){
	if(sum>maxn*2&&len>=3){
		cnt=(cnt+1)%mod;
	}
	for(int i=k;i<=n;i++){
		sum+=a[i];
		len++;
		maxn=a[i];
		dfs(maxn,len,sum,i+1);
		sum-=a[i];
		len--;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	dfs(0,0,0,1);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
