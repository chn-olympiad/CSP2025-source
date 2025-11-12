#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int T,n,m,ans;
struct node{
	pair<int,int> val[4];
	int a,b,c,W;
}O[N];
vector<int> r[3];
void rec(){
	for(int e:r[1]) ans += O[e].a;
	for(int e:r[2]) ans += O[e].b;
	for(int e:r[3]) ans += O[e].c;
}
bool cmp(int a,int b){
	return O[a].val[3].first - O[a].val[2].first > O[b].val[3].first - O[b].val[2].first;
}
void solve(){
	ans = 0;
	r[1].clear(),r[2].clear(),r[3].clear();
	cin>>n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		O[i].a = a,O[i].b = b,O[i].c = c;
		O[i].val[1] = {a,1},O[i].val[2] = {b,2},O[i].val[3] = {c,3};
		sort(O[i].val+1,O[i].val+4);
		O[i].W = O[i].val[3].second;
		r[O[i].W].push_back(i);
	}
	if((int)r[1].size()<=n/2 && (int)r[2].size()<=n/2 && (int)r[3].size()<=n/2){
		rec();
		cout<<ans<<'\n';
		return;
	}
	if((int)r[1].size()>n/2){
		sort(r[1].begin(),r[1].end(),cmp);
		for(int i=n/2;i<(int)r[1].size();i++){
			r[O[r[1][i]].val[2].second].push_back(r[1][i]);
		}
		while((int)r[1].size()>n/2) r[1].pop_back();
	}
	if((int)r[2].size()>n/2){
		sort(r[2].begin(),r[2].end(),cmp);
		for(int i=n/2;i<(int)r[2].size();i++){
			r[O[r[2][i]].val[2].second].push_back(r[2][i]);
		}
		while((int)r[2].size()>n/2) r[2].pop_back();
	}
	if((int)r[3].size()>n/2){
		sort(r[3].begin(),r[3].end(),cmp);
		for(int i=n/2;i<(int)r[3].size();i++){
			r[O[r[3][i]].val[2].second].push_back(r[3][i]);
		}
		while((int)r[3].size()>n/2) r[3].pop_back();
	}
	rec();
	cout<<ans<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--) solve();
	return 0;
}

