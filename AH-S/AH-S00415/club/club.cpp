#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct s{
	int id;
	long long val;
	bool operator < (const s &x)const{
		return x.val<val;
	}
};
s x;
priority_queue<s> q[3];
long long t,n,a[N][3],nxt[N][3],maxn[N][3],cnt[N],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		scanf("%lld",&n);
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				maxn[i][0]=0;
				if(a[i][1]>=a[i][2]) maxn[i][1]=1,maxn[i][2]=2;
				else maxn[i][1]=2,maxn[i][2]=1;
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				maxn[i][0]=1;
				if(a[i][0]>=a[i][2]) maxn[i][1]=0,maxn[i][2]=2;
				else maxn[i][1]=2,maxn[i][2]=0;
			}else{
				maxn[i][0]=2;
				if(a[i][0]>=a[i][1]) maxn[i][1]=0,maxn[i][2]=1;
				else maxn[i][1]=1,maxn[i][2]=0;
			}
			nxt[i][0]=a[i][maxn[i][0]]-a[i][maxn[i][1]];
			nxt[i][1]=a[i][maxn[i][1]]-a[i][maxn[i][2]];
		}
		for(int i=1;i<=n;i++){
			if(cnt[maxn[i][0]]<n/2) ans+=a[i][maxn[i][0]],q[maxn[i][0]].push({i,nxt[i][0]}),cnt[maxn[i][0]]++;
			else{
				x=q[maxn[i][0]].top();
				if(nxt[i][0]>x.val){
					q[maxn[i][0]].pop();
					q[maxn[i][0]].push({i,nxt[i][0]});
					ans+=a[i][maxn[i][0]]-x.val;
				}else{
					ans+=a[i][maxn[i][1]];
				}
			}
		}
		for(int i=0;i<=2;i++) while(!q[i].empty()) q[i].pop();
		printf("%lld\n",ans);
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
