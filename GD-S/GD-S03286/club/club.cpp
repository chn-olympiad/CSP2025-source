#include<bits/stdc++.h>

using namespace std;

const int N=1e5+1;
int T,n,ans,sum,cnt[4],a1,a2,a3;
bool vis[N];
struct pos{
	int x,to,i;
};
vector<pos>q;

bool cmp(pos x,pos y){
	return x.x<y.x;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=sum=0;
		memset(cnt,0,sizeof(cnt));
		q.clear();
		for(int i=1;i<=n;i++){
			cin>>a1>>a2>>a3;
			ans+=a1,vis[i]=0,cnt[1]++;
			q.push_back({a1-a2,2,i}),q.push_back({a1-a3,3,i});
		}
		sort(q.begin(),q.end(),cmp);
		for(pos k:q){
			if(sum<(n>>1)){
				if(!vis[k.i]){
					vis[k.i]=1,ans-=k.x,sum++,cnt[k.to]++,cnt[1]--;
				}
			}
			else{
				if(!vis[k.i] && cnt[k.to]<(n>>1) && ans-k.x>ans){
					vis[k.i]=1,ans-=k.x,sum++,cnt[k.to]++,cnt[1]--;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

