#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second 
#define pb push_back
using namespace std;
const int N = 1e5+5; 
struct temp{
	int val,id;
	bool operator <(const temp &x) const{
		return val>x.val;
	}
};
struct node{
	temp maxx[3];
}a[N];
inline bool cmp(node a,node b){
	if(a.maxx[0].val==b.maxx[0].val){
		if(a.maxx[1].val==b.maxx[1].val){
			return a.maxx[2].val>b.maxx[2].val;
		}
		return a.maxx[1].val>b.maxx[1].val;
	}	
	return a.maxx[0].val>b.maxx[0].val;
}
int n;
int cnt[5];
vector<int> v[4]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i].maxx[0].val,&a[i].maxx[1].val,&a[i].maxx[2].val);
			a[i].maxx[0].id=1;
			a[i].maxx[1].id=2;
			a[i].maxx[2].id=3;
			sort(a[i].maxx,a[i].maxx+3);
		}
		cnt[1]=cnt[2]=cnt[3]=0;
		sort(a+1,a+n+1,cmp);
		ll ans=0;
		for(int i=1;i<=3;++i) v[i].clear();
		for(int i=1;i<=n;++i){
			ans+=a[i].maxx[0].val;
			cnt[a[i].maxx[0].id]++; 
			v[a[i].maxx[0].id].pb(a[i].maxx[0].val-a[i].maxx[1].val);
		}
		for(int i=1;i<=3;++i){
			if(cnt[i]>n/2){
				int t=cnt[i]-n/2;
				sort(v[i].begin(),v[i].end());
				for(int j=1;j<=t;++j){
					ans-=v[i][j-1];
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
