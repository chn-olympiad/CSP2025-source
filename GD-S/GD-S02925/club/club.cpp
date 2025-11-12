#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e5+10,A=2e4+10;
int n;
int ans;
array<vector<int>,10> del;
bool cmp(pii i,pii j){
	return i.first>j.first;
}
void dele(int j){
	if((int)del[j].size()<=n/2) return;
	sort(del[j].begin(),del[j].end());
	for(int i=0;i<(int)del[j].size()-n/2;i++) ans-=del[j][i];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		del[1].clear(),del[2].clear(),del[3].clear();
		cin>>n;
		for(int i=1;i<=n;i++){
			pii ai[4];
			for(int j=1;j<=3;j++) cin>>ai[j].first,ai[j].second=j;
			sort(ai+1,ai+3+1,cmp);
			ans+=ai[1].first;
			del[ai[1].second].emplace_back(ai[1].first-ai[2].first);
		}
		for(int j=1;j<=3;j++) dele(j);
		cout<<ans<<'\n';
	}
	return 0;
}
