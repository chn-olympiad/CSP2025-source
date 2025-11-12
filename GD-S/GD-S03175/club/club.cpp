#include<bits/stdc++.h>
using namespace std;
#define FILE "club"
int n;
int a[100001][3];
vector<int> vs[3];
long long ans=0;
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<3;i++){
			vs[i].clear();
		}
		ans=0;
		for(int i=1;i<=n;i++){
			int cid=0,cost=2147483647;
			for(int j=0;j<3;j++){
				cin >> a[i][j];
				if(a[i][j]>a[i][cid])	cid=j;
			}
			for(int j=0;j<3;j++){
				if(j==cid)	continue;
				cost=min(cost,a[i][cid]-a[i][j]);
			}
			ans+=a[i][cid];
			vs[cid].push_back(cost);
		}
		for(int j=0;j<3;j++){
			sort(vs[j].begin(),vs[j].end());
		}
		if(vs[0].size()<vs[1].size())	swap(vs[0],vs[1]);
		if(vs[0].size()<vs[2].size())	swap(vs[0],vs[2]);
		int cl=max(0,int(vs[0].size()-n/2));
		for(int j=0;j<cl;j++){
			ans-=vs[0][j];
		} 
		cout << ans << '\n';
	}
	return 0;
}

