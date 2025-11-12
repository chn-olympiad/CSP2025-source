#include <bits/stdc++.h>
using namespace std;
int T,n;
struct node{
	int x,id;
} a[100010][4];
vector<int> cnt[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=3;i++) cnt[i].clear(),cnt[i].shrink_to_fit();
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j].x;
				a[i][j].id=j;
			}
			sort(a[i]+1,a[i]+4,[](node aa,node bb){
				return aa.x>bb.x;
			});
			ans+=a[i][1].x;
		}
		for(int i=1;i<=n;i++) cnt[a[i][1].id].push_back(i);
		for(int j=1;j<=3;j++){
			if(int(cnt[j].size())<=(n/2)) continue;
			sort(cnt[j].begin(),cnt[j].end(),[](int aa,int bb){
				return (a[aa][1].x-a[aa][2].x)<(a[bb][1].x-a[bb][2].x);
			});
			for(int i=0;i<int(cnt[j].size())-(n/2);i++) ans-=(a[cnt[j][i]][1].x-a[cnt[j][i]][2].x);
			break;
		}
		cout<<ans<<'\n';
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
