#include<bits/stdc++.h>
using namespace std;
long long cases,n,a[100100][4],pos[100100],cnt[4],ans;
priority_queue<long long> pq;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&cases);
	for(;cases;--cases){
		for(;!pq.empty();pq.pop());
		ans=0;
		scanf("%lld",&n);
		cnt[0]=0;
		cnt[1]=0;
		cnt[2]=0;
		for(int i=1;i<=n;++i){
			scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
			long long maxn=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=maxn;
			if(maxn==a[i][0]){
				pos[i]=0;
				++cnt[0];
			}else if(maxn==a[i][1]){
				pos[i]=1;
				++cnt[1];
			}else{
				pos[i]=2;
				++cnt[2];
			}
		}
		for(int i:{0,1,2}){
			if(cnt[i]>(n>>1)){
				// cout<<i<<endl;
				int t1=i-1,t2=i+1;
				if(t1==-1)
				t1=2;
				if(t2==3)
				t2=0;
				for(int j=1;j<=n;++j){
					if(pos[j]==i){
						pq.push(max(a[j][t1]-a[j][i],a[j][t2]-a[j][i]));
					}
				}
				int tem=cnt[i]-(n>>1);
				for(;tem;--tem){
					ans+=pq.top();
					pq.pop();
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}