#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010;
int n,a[N],maxn=-1,b[N],ans;
int f[N],la[N];
void dfs(int dep,int x,int xia){
	if(dep==x+1){
		int ma=-1,s=0;
		for(int i=1;i<=x;i++){
			ma=max(ma,b[i]);
			s+=b[i];
		}
		if(s>ma*2) ++ans;
		return;
	}
	for(int i=xia+1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			b[dep]=a[i];
			dfs(dep+1,x,i);
			b[dep]=0;
			f[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+1+n);
	if(maxn==1) cout<<n*(n-1)*(n-2)/6;
	else if(n<=10){
		for(int i=3;i<=n;i++) dfs(1,i,0);
		cout<<ans; 
	}
	return 0;
}
