#include <queue>
#include <cstdio>
#include <algorithm>

typedef long long ll;

const int N=1e5+10;

int t,n;
ll res;
ll a[N][3];
int tot[3];

void dfs(int x,int cnt[],ll sum) {
	if(x>n) res=std::max(res,sum);
	int p=-1,q=-1;
	for(int i=0;i<3;i++) {
		if(p==-1 || a[x][p]<a[x][i]) q=p,p=i;
		else if(q==-1 || a[x][q]<a[x][i]) q=i;
	}
//	printf("qwq %d %d %d %d %d %d %d\n",x,cnt[0],cnt[1],cnt[2],sum,p,q);
	++cnt[p];
	if(cnt[p]<=n/2) dfs(x+1,cnt,sum+a[x][p]);
	--cnt[p];
	++cnt[q];
	if(cnt[q]<=n/2) dfs(x+1,cnt,sum+a[x][q]);
	--cnt[q];
}

void sol1() {
	tot[0]=tot[1]=tot[2]=0;
	res=0;
//	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) scanf("%lld",&a[i][j]);
	dfs(1,tot,0);
	printf("%lld\n",res); 
}

ll ans[3];
int cnt[3];
std::priority_queue<std::pair<ll,int>> que[3]; 

void init() {
	for(int i=0;i<3;i++) {
		while(!que[i].empty()) que[i].pop();
	}
}

void sol2() {
	init();
//	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=0;j<3;j++) scanf("%lld",&a[i][j]);
	ans[0]=ans[1]=ans[2]=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++) {
		int p=-1,q=-1;
		for(int j=0;j<3;j++) {
			if(p==-1 || a[i][j]>a[i][p]) q=p,p=j;
			else if(q==-1 || a[i][j]>a[i][q]) q=j;
		}
//		printf("qwq %d %d %d\n",i,p,q);
		if(cnt[p]<n/2) {
			++cnt[p];
			ans[p]+=a[i][p];
			que[p].push(std::make_pair(-a[i][p],i));
		} else {
			auto cur=que[p].top();
			int x=cur.second;
//			if(a[i][p]-a[x][p]<0) continue;
//			que[p].pop();
			int pp=-1;
			for(int j=0;j<3;j++) {
				if(j==p) continue;
				if(pp==-1 || a[x][j]>a[x][pp]) pp=j;
			}
			if(a[i][p]+a[x][pp]<a[x][p]+a[i][q]) {
				que[q].push(std::make_pair(-a[i][q],i));
				cnt[q]++;ans[q]+=a[i][q];
			} else {
				que[p].pop(); 
				ans[p]+=a[i][p]-a[x][p];ans[pp]+=a[x][pp];
				++cnt[pp];
				que[p].push(std::make_pair(-a[i][p],i));
				que[pp].push(std::make_pair(-a[x][pp],x));
			}
		}
	}
	printf("%lld\n",ans[0]+ans[1]+ans[2]);
}

void sol() {
	scanf("%d",&n);
	if(n<=10) sol1();
	else sol2();
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) sol();
	return 0;
}
