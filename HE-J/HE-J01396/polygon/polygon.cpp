#include<bits/stdc++.h>
using namespace std;
const int N=5055;
long long ans,mod=998244353;
int n,a[N];
void dfs(int cnt,int yc,int q,int qsum,int qmax){
	if(yc==cnt) return ;
	for(int i=q+1;i<=n-cnt+yc+1;i++){
		if(yc==cnt-1){
			if(qsum+a[i]>max(qmax,a[i]*2)) ans=(ans+1)%mod;
			else break;
		}else dfs(cnt,yc+1,i,qsum+a[i],max(qmax,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		dfs(i,0,0,0,0);
	}
	cout<<ans;
	return 0;
}
