#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int a[N][5];
struct Node{
	int val, id, cp;
}cnt[3*N];
int num[5];
bool vis[N];
bool cmp(Node a1, Node a2){
	return a1.val>a2.val;
}
int n;
ll ans=0;
void dfs(int x, ll now){
	if(x>n){
		ans=max(ans, now);
		return;
	}
	for(int i=1;i<=3;i++){
		if(num[i]<n/2){
			num[i]++;
			dfs(x+1, now+a[x][i]);
			num[i]--;
		}
	}
}
		
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%d", &n);
		int tot=0;
		int flag=0;
		for(int i=1;i<=n;i++){
			int t=0;
			for(int j=1;j<=3;j++){
				scanf("%d", &a[i][j]);
				if(a[i][j]) t=1;
				num[i]=0;
				cnt[++tot].val=a[i][j];
			}
			flag+=t;
		}
		ans=0;
		if(flag==1){
			sort(cnt+1, cnt+3*n+1, cmp);
			for(int i=1;i<=(n>>1);i++){
				ans+=cnt[i].val;
			}
			printf("%lld\n", ans);
			continue;
		}
		if(n>10){
			int now=0;
			for(int i=1;i<=3*n;i++){
				if(now==n) break;
				if(num[cnt[i].cp]<(n>>1)&&!vis[cnt[i].id]){
					num[cnt[i].cp]++;
					vis[cnt[i].id]=true;
					now++;
					ans+=cnt[i].val;
					//cout<<cnt[i].id<<" "<<cnt[i].cp<<endl;
				}
			}
		}
		else dfs(1, 0);
		printf("%lld\n", ans);
	}
	return 0;
}