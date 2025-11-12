#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, sum[4], ans=0;//sum为各部门人数 
const int MAXN=2e5;
struct Node1{
	ll x, sc;//sc为喜好值，x为该同学编号 
};
vector<Node1> tot[4];
struct Node{
	ll a[4], numx=1, srt[4], m;//a[i]为部门i分数，numx为最终选定的部门排名，srt[i]为排行第i名的部门, m为第一与第二相差的分数 
	void cinn(){
		cin >> a[1] >> a[2] >> a[3];
	}
	void sor(){
		for(ll i=1; i<=3; i++){
			if(a[i]==max(a[1], max(a[2], a[3])))srt[1]=i;
			if(a[i]==min(a[1], min(a[2], a[3])))srt[3]=i;
		}
		srt[2]=6-srt[1]-srt[3];
		m=a[srt[1]]-a[srt[2]]; 
	}	
	void clear(){
		for(ll i=0; i<4; i++){
			a[i]=0;
			srt[i]=0;
		}
		numx=1;
	}
	
};
Node a[MAXN];
bool cmp1(Node1 x, Node1 y){
	return a[x.x].m<a[y.x].m;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		cin >> n;
		for(ll i=0; i<MAXN; i++){
			a[i].clear();
		}
		for(ll i=1; i<=3; i++){
			tot[i].clear();
			sum[i]=0;
		}
		ans=0;
		for(ll i=1; i<=n; i++){
			a[i].cinn();
			a[i].sor();
		}
		for(ll i=1; i<=n; i++){
			tot[a[i].srt[a[i].numx]].push_back({i, a[i].a[a[i].srt[a[i].numx]]});
		}
		for(ll i=1; i<=3; i++){
			sort(tot[i].begin(), tot[i].end(), cmp1);
		}
		for(ll i=1; i<=3; i++){
			for(ll j=0; j<tot[i].size(); j++){
				ans+=tot[i][j].sc;
			}
		}
		if(tot[1].size()<=n/2&&tot[2].size()<=n/2&&tot[3].size()<=n/2){
			cout << ans << endl;
			continue;
		}
		for(ll i=1; i<=3; i++){
			if(tot[i].size()>n/2){
				for(ll j=0; j<(tot[i].size()-n/2); j++){
					ans-=a[tot[i][j].x].m;
				}
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
