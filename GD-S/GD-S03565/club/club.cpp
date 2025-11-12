#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=2e6+5;
int n,id[maxn],cnt[3];
struct node{
	int l[3];
	bool operator<(const node &o){
		return l[0]<o.l[0];
	}
}a[maxn];
ll ret=0,ans=0;
void dfs(int u){
	if(u>n){
		ans=max(ans,ret);
		return ;
	}
	for(int i=0;i<3;i++){
		if(cnt[i]<n/2){
			ret+=a[u].l[i];
			cnt[i]++;
			dfs(u+1);
			ret-=a[u].l[i];
			cnt[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&n);
	bool f=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&a[i].l[j]);
			if(j && a[i].l[j]) f=0;
		}
	}
	dfs(1);
	printf("%lld\n",ans);
	return 0;
} 
