#include <bits/stdc++.h>
#define ma(a,b) a>=b ? a : b
#define mset(a) memset(a,0,sizeof a)
using namespace std;
const int N=1e5+10;
int t,n,max2,max3,ans,cnt[4],mem[N];
struct Node{
	int d[4],maxd;
}a[N];
inline bool cmp(Node x,Node y){
	for (int i=1;i<=3;i++)
		if (x.d[i]!=y.d[i]) return x.d[i]>y.d[i];
	return 1;
}
int dfs(int u,int sum,int cmd){
//	cout<<u<<' '<<sum<<' '<<cmd<<endl;
	if (mem[u]) return mem[u];
	if (u==n+1){
		ans=ma(ans,sum);
		return 0;
	}
	for (int i=1;i<=3-cmd;i++){
		if (cnt[i]<n/2 && sum+a[u].d[i]>=mem[u]){
			cnt[i]++;
			mem[u]=ma(mem[u],dfs(u+1,sum+a[u].d[i],cmd));
			cnt[i]--;
		}
	}
	return mem[u];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		ans=max2=max3=0;
		mset(a);
		mset(cnt);
		mset(mem);
		for (int i=1;i<=n;i++){
			cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
			a[i].maxd=ma(a[i].d[1],(ma(a[i].d[2],a[i].d[3])));
			max2=ma(max2,a[i].d[2]);
			max3=ma(max3,a[i].d[3]);
		}
		sort(a+1,a+n+1,cmp);
		if (max2==max3 && !max2)
			for (int i=1;i<=n/2;i++) ans+=a[i].d[1];
		else if (!max3) dfs(1,0,1);
		else dfs(1,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
