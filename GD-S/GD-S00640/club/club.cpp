#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+5;
int t,n;
int a[N][4];
int bes[N],god[N];
struct Node{
	int b,g;
	int idxg;
	bool operator<(const Node&oth)const{
		return b-g>oth.b-oth.g;
	}
};
int cnt[4];
int idx_max(int p){
	int res=0;
	for(int i=1;i<=3;i++)
	if(a[res][p]<a[i][p]) res=i;
	return res;
}
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		priority_queue<Node> q[4];
		memset(bes,0,sizeof bes);
		memset(god,0,sizeof god);
		memset(cnt,0,sizeof cnt);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a[i][0]=-1;
			for(int j=1;j<=3;j++){
				if(a[i][j]>=a[i][bes[i]]) god[i]=bes[i],bes[i]=j;
				else if(a[i][j]>=a[i][god[i]]) god[i]=j;
			}
			if(cnt[bes[i]]==n/2){
				int bth=q[bes[i]].top().b,gth=q[bes[i]].top().g,gid=q[bes[i]].top().idxg;
				if(bth-gth<=a[i][bes[i]]-a[i][god[i]]){
					q[bes[i]].pop();
					q[bes[i]].push({a[i][bes[i]],a[i][god[i]],god[i]});
					q[gid].push({bth,gth,gid});
					ans+=a[i][bes[i]]-bth+gth;
					cnt[gid]++;
				}
				else{
					q[god[i]].push({a[i][bes[i]],a[i][god[i]],god[i]});
					ans+=a[i][god[i]];
					cnt[god[i]]++;
				}
			}
			else{
				ans+=a[i][bes[i]];
				q[bes[i]].push({a[i][bes[i]],a[i][god[i]],god[i]});
				cnt[bes[i]]++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
