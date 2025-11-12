#include <bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[100010][4],cnt[4],p,b,h[100010],ans,t;
bool used[100010];
struct node{
	int to;
	int cost;
	int id;
};
node swp[200010],l;
bool cmp(node a,node b){
	return a.cost<b.cost;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0,b=0,t=0,memset(h,0,sizeof(h)),memset(cnt,0,sizeof(cnt));
		memset(used,0,sizeof(used));
		p=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=max({a[i][1],a[i][2],a[i][3]});
			ans+=mx;
			if(mx==a[i][1]){
				h[i]=1,cnt[1]++;
			}else if(mx==a[i][2]){
				h[i]=2,cnt[2]++;
			}else{
				h[i]=3,cnt[3]++;
			}
		}
		for(int i=1;i<=3;i++) if(cnt[i]>p) b=i;
		if(b==0){
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				if(h[i]==b){
					t++;
					if(b==1){
						swp[t].cost=a[i][1]-a[i][2],swp[t].to=2,swp[t].id=i,t++;
						swp[t].cost=a[i][1]-a[i][3],swp[t].to=3,swp[t].id=i;
					}
					if(b==2){
						swp[t].cost=a[i][2]-a[i][1],swp[t].to=1,swp[t].id=i,t++;
						swp[t].cost=a[i][2]-a[i][3],swp[t].to=3,swp[t].id=i;
					}
					if(b==3){
						swp[t].cost=a[i][3]-a[i][1],swp[t].to=1,swp[t].id=i,t++;
						swp[t].cost=a[i][3]-a[i][2],swp[t].to=2,swp[t].id=i;
					}
				}
			}
			sort(swp+1,swp+t+1,cmp);
			for(int i=1;i<=t;i++){
				if(!used[swp[i].id]){
					used[swp[i].id]=1;
					ans=ans-swp[i].cost;
					cnt[swp[i].to]++,cnt[b]--;
				}
				if(cnt[b]==p){
					cout<<ans<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
