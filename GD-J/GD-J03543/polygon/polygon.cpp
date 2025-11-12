#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
void init(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
}
int n,ans,ma,mi;
int a[5001],sum[5001];
int jc[5001];
int ls[5001];
bool bj[5001],bjj[5001];
void dfs(int maa,int he,int zs){
	int qu=0;
	for(int i=mi;i<=ma;i++){
		if(bj[i]){
			qu=i;
			break;
		}
	}
	if(!qu){
		for(int i=1;i<=ma;i++){
			if(ls[i]){
				cout<<i<<" ";
			}
		}
		cout<<"\n";
		if(zs>=3){
			if(he>maa*2){
				int cnt=1;
				for(int i=1;i<=ma;i++){
					if(!ls[i]){
						continue;
					}
					int zhi=jc[sum[i]]/jc[ls[i]]/jc[sum[i]-ls[i]]%mod;
					cnt=cnt*zhi%mod;
				}
				ans+=cnt;
			}
		}
		return; 
	}
	bj[qu]=0;
	for(int i=1;i<=sum[qu];i++){
		ls[qu]+=i;
		dfs(max(maa,qu),he+qu*i,zs+i);
		ls[qu]-=i;
	}
	dfs(maa,he,zs);
}
signed main(){
	cin.tie(nullptr),cout.tie(nullptr),ios::sync_with_stdio(false);
	init();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
		ma=max(ma,a[i]);
		mi=min(mi,a[i]);
	}
	for(int i=1;i<=ma;i++){
		if(sum[i]){
			bj[i]=1;
		}
	}
	if(n<3){
		return cout<<0,0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*ma){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=1;
		for(int j=1;j<=i;j++){
			l=(l*j)%mod;
		}
		jc[i]=l%mod;
	}
	jc[0]=1;
	if(ma==1){
		for(int i=3;i<=n;i++){
			int zhi=jc[n]/jc[i]/jc[n-i]%mod;
			ans=(ans+zhi)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 
