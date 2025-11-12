#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
#define ll long long
int T;
ll ans;
struct mark{
	int val,per,kind;
	bool use = 0;
//	bool operator > (const mark &t)const{
//		return val > t.val;
//	}
}a[N];
bool vis[N];

bool cmp(mark x,mark y){
	return x.val > y.val;
} 

void solve(){
	int n;
	ans = 0;
	int cnt1 = 0,cnt2 = 0,cnt3 = 0;
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	int limit = n / 2;
	int idx = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			scanf("%d",&a[idx].val);
//			cin>>a[idx].val;
			a[idx].per = i;
			a[idx].kind = j;
			idx++;
		}
	}sort(a + 1,a + idx,cmp);
	if(n == 2){
		for(int i = 1;i<=3;i++){
			for(int j = 4;j<=6;j++){
				if((i == 1 && j == 4) || (i == 2 && j == 5) || (i == 3 && j == 6)){
					continue;
				}
				ans = max(ans,(ll)a[i].val + a[j].val);
			}
		}printf("%lld\n",ans);
		return ;
	}
	for(int i = 1;i<idx;i++){
		if(!vis[a[i].per]){
			if(a[i].kind == 1){
				if(cnt1 < limit){
					cnt1++;
					a[i].use = 1;
					vis[a[i].per] = 1;
					ans += a[i].val;
				}
			}
			else if(a[i].kind == 2){
				if(cnt2 < limit){
					cnt2++;
					a[i].use = 1;
					vis[a[i].per] = 1;
					ans += a[i].val;
				}
			}
			else{
				if(cnt3 < limit){
					cnt3++;
					a[i].use = 1;
					vis[a[i].per] = 1;
					ans += a[i].val;
				}
			}
		}
	}printf("%lld\n",ans);

}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}
