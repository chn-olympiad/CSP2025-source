#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int xor_sum[N],n,k,tot,val[N*N],flag[N*N];
int maxn=0;
struct w{
	int l,r;
}a[N*N];
void dfs(int i,int sum){
	flag[i]=1;
	maxn=max(maxn,sum);
	for(int j=i+1;j<=tot;j++){
		if(a[j].l<=a[i].r || flag[j]){
			continue;
		}
		dfs(j,sum+1);
	}
	return ;
}
bool cmp(w x,w y){
	if(x.r<y.r) return 1;
	else if(x.r== y.r){
		if(x.l<y.l){
			return 1;
		}
		return 0;
	}else{
		return 0;
	}
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	xor_sum[0]=0;
	cin>>n>>k;
	int x;
	for(int i=1;i<=n;i++){
		cin>>x;
		xor_sum[i]=(xor_sum[i-1]^x);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((xor_sum[j]^xor_sum[i-1])==k){
				a[++tot].l=i;
				a[tot].r=j;
			}
		}
	}
	sort(a+1,a+tot+1,cmp);
	int ans=0;
	for(int i=1;i<=tot;i++){
		maxn=0;
		dfs(i,1);
		ans=max(maxn,ans);
	}
	cout<<ans;
	return 0;
} 