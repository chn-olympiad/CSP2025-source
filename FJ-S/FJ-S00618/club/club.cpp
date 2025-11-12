#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define lc(p) ((p)*2)
#define rc(p) ((p)*2+1)
#define mkpr make_pair
#define fir first
#define sec second
using namespace std;
const int N=100005;
//¶à²âÇå¿Õ
int T;
int n;
int a[N][3];
int tmp[3];
int tot;
bool cmp(int x,int y) {
	return a[tot][x]>a[tot][y];
}
bool cmp2(int x,int y) {
	return a[x][1]-a[x][0]>a[y][1]-a[y][0];
}
vector<int>g[3];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(0);
	cin>>T;
	while(T--) {
		cin>>n;
		LL ans=0;
		for(int j=0; j<3; j++)g[j].clear();
		for(int i=1; i<=n; i++) {
			tot=i;
			for(int j=0; j<3; j++) {
				cin>>a[i][j];
				tmp[j]=j;
			}
			sort(tmp,tmp+3,cmp);
			sort(a[i],a[i]+3,greater<int>());
			/*
			for(int j=0;j<3;j++){
				b[i][j]=tmp[j];
			}*/
			g[tmp[0]].push_back(i);
			ans+=a[i][0];
		}
		
		for(int j=0;j<3;j++){
			if(g[j].size()>n/2){
				sort(g[j].begin(),g[j].end(),cmp2);
			}
			int cnt=g[j].size()-n/2;
			for(int i=0;i<cnt;i++){
				int x=g[j][i];
				ans+=a[x][1]-a[x][0];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
1. tan

-a+b<0

b-a<0 max

=n/2

2. binary

check

max

4 2 1
3 2 4
5 3 4
3 5 1

1 3 1 2




*/
