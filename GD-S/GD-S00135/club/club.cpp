//容易发现，最多最多只有一个社团会满员 
#include<bits/stdc++.h>
using namespace std;

int const maxn = 1e5+5;
int a[maxn][5];
vector<int> e[5];
int pm[maxn][5];

int tp[5];

bool cmp(int aa,int bb){
	return a[aa][pm[aa][1]]-a[aa][pm[aa][2]] < a[bb][pm[bb][1]]-a[bb][pm[bb][2]];
}

inline void work(){
	e[1].clear();
	e[2].clear();
	e[3].clear();
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 3; ++j){
			cin>>a[i][j];
			tp[j] = a[i][j];
			pm[i][j] = j;
		}
		sort(pm[i]+1,pm[i]+4,[](int aa,int bb){
			return tp[aa] > tp[bb];
		});
//		for(int j = 1; j <= 3; ++j)  cout<<pm[i][j]<<' ';
//		cout<<'\n';
		e[pm[i][1]].push_back(i);
		ans += a[i][pm[i][1]];
	}
	int id = -1;
	for(int i = 1; i <= 3; ++i){
//		cout<<e[i].size()<<'\n';
		if(e[i].size() > (n>>1))  id = i;
	}
//	cout<<ans<<'\n';
	if(id == -1){
		cout<<ans<<'\n';
		return ;
	}
	sort(e[id].begin(),e[id].end(),cmp);
	for(int i = 0; i < e[id].size()-(n>>1); ++i){
		int y = e[id][i];
//		cout<<a[e[id][i]][pm[id][1]]-a[e[id][i]][pm[id][2]]<<'\n';
		ans -= a[y][pm[y][1]]-a[y][pm[y][2]];
	}
	cout<<ans<<'\n';
	return ;
}

int main(){
	ios:: sync_with_stdio(0);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)  work();
	return 0;
} 
