#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,k;
int a[MAXN],sum[MAXN],pre[MAXN];
int f[MAXN],ans,ansn;
map<int,int> m;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]^sum[i-1];
		pre[i]=m[sum[i]^k];
		if(pre[i]==0&&sum[i]!=k) pre[i]=-1;
		m[sum[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(pre[i]==-1){
			f[i]=f[i-1];
			continue ;
		}
		f[i]=max(f[pre[i]]+1,f[i-1]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
//注意：区间要求不相交即可，并非区间必须相邻 