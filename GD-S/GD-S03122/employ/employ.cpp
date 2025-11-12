#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int mod=998244353;
int n,m,s[N],c[N];
int a[N],total;
void dfs(int dep){
	if(dep==n+1){
		int ans=0,cnt=0; 
		for(int i=1;i<=n;i++){
			if(ans>=a[i]||s[i]==0){
				ans++;
			}
			else {
				cnt++;
			}
		}
		if(cnt>=m) total=(total+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==-1){
			a[i]=c[dep];
			dfs(dep+1);
			a[i]=-1;
		}
	} 
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=(c-'0');
		if(s[i]==0) flag=0;
	}
	for(int i=1;i<=n;i++ ) cin>>c[i],a[i]=-1;
	if(m==n){
		total=1;
		for(int i=1;i<=n;i++){
			if(s[i]==0) {
				printf("0\n");
				return 0;
			}
			total=total*i%mod;
		}
		printf("%lld\n",total);
		return 0;
	}
	dfs(1);
	printf("%ll\n",total);
	return 0;
}
