#include<bits/stdc++.h>

using namespace std;
const int N=1e5+5;

int n,a[N][3],mp[3],tp,ans,flaga=1,flagb=1;

void dfs(int x,int sum) {
//	cout<<sum<<endl;
	if(mp[0]>n/2||mp[1]>n/2||mp[2]>n/2) return;
	if(x>n) {
		ans=max(ans,sum);
		return ;
	}
	mp[0]++;
	dfs(x+1,sum+a[x][0]);
	mp[0]--;
	mp[1]++;
	dfs(x+1,sum+a[x][1]);
	mp[1]--;
	mp[2]++;
	dfs(x+1,sum+a[x][2]);
	mp[2]--;
}
//bool cmp
struct node {
	int a,b;
}tmp[N];
int tmp1[N];
void solve() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		if(!(a[i][1]==0&&a[i][2]==0&&flaga)) flaga=0;
		if(!(a[i][2]==0&&flagb)) flagb=0;
		tmp1[i]=a[i][0];
	}
	if(flagb) {
		for(int i=1;i<=n;i++) tmp[i].a=a[i][0],tmp[i].b=a[i][1];
		sort(tmp+1,tmp+n+1,[](node a,node b) {
			return max(a.a,a.b)>max(b.a,b.b);
		});
		ans=0;
		for(int i=1;i<=n;i++) {
			if(tmp[i].a>tmp[i].b&&mp[0]<n/2) ans+=tmp[i].a,mp[0]++;
			else ans+=tmp[i].b,mp[1]++;
		}
		printf("%d\n",ans);
		return;
	}
	else if(flaga) {
		sort(tmp1+1,tmp1+n+1,greater<int>());
		ans=0;
		for(int i=1;i<=n/2;i++) ans+=tmp1[i];
		printf("%d\n",ans);
		return;
	}
	ans=0;
	memset(mp,0,sizeof(mp));
	dfs(1,0);
	printf("%d\n",ans);
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
