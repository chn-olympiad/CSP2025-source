#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N][5],t[N];
vector<int> e[3];
void solve(){
	e[1].clear();
	e[2].clear();
	e[3].clear();
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		t[i]=0;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			t[i]=max(t[i],a[i][j]);
		}
//		cout<<i<<","<<t[i]<<endl;
		for(int j=1;j<=3;j++){
			if(a[i][j]==t[i]){
				ans+=t[i];
				t[i]=t[i]-a[i][1]-a[i][2]-a[i][3]+t[i]+min(min(a[i][1],a[i][2]),a[i][3]);
				e[j].push_back(t[i]);
				break;
			}
		}
	}
	if(e[1].size()>(n/2)){
		sort(e[1].begin(),e[1].end());
		for(int i=0;i<(e[1].size()-(n/2));i++){
			ans-=e[1][i];
		}
	}else if(e[2].size()>(n/2)){
		sort(e[2].begin(),e[2].end());
		for(int i=0;i<(e[2].size()-(n/2));i++){
			ans-=e[2][i];
		}
	}else if(e[3].size()>(n/2)){
		sort(e[3].begin(),e[3].end());
		for(int i=0;i<(e[3].size()-(n/2));i++){
			ans-=e[3][i];
		}
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
