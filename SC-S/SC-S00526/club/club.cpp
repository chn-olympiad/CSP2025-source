#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=100000;

int T;
int n;
int a[N+1][3+1];
vector<int> qu[3+1];
int ans;

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=3;i++) qu[i].clear();
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int t=max({a[i][1],a[i][2],a[i][3]});
			int t_=a[i][1]+a[i][2]+a[i][3]-t-min({a[i][1],a[i][2],a[i][3]});
			ans+=t;
			if(t==a[i][1]) qu[1].push_back(t_-t);
			else if(t==a[i][2]) qu[2].push_back(t_-t);
			else qu[3].push_back(t_-t);
		}
		for(int i=1;i<=3;i++){
			if((int)qu[i].size()>(n>>1)){
				sort(qu[i].begin(),qu[i].end());
				for(int j=qu[i].size()-1;j>=(n>>1);j--) ans+=qu[i][j];
				break;
			}
		}
		cout<<ans<<endl;
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