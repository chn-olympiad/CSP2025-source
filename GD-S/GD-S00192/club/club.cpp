#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
const int maxn=5e5+100;
int t,n,a[maxn][4];
vector<int> ans[4];
struct node{
	int v,id;
}c[4];
bool cmp(node a,node b){
	return a.v>b.v;
}
void work(){
	cin>>n;
	int sum=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=3;j++){
			cin>>c[j].v;
			c[j].id=j;
		}
		sort(c+1,c+4,cmp);sum+=c[1].v;
		ans[c[1].id].push_back(c[1].v-c[2].v);
	}
	for (int i=1;i<=3;i++){
		sort(ans[i].begin(),ans[i].end());
		if ((int)ans[i].size()>n/2){
			int k=ans[i].size()-n/2;
			for (int j=0;j<k;j++){
				sum-=ans[i][j];
			}
		}
		ans[i].clear();
	}
	cout<<sum<<'\n';
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while (t--){work();}
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
