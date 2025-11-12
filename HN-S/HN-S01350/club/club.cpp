#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

int t;//
int n;//
struct ab{
	int x,id; 
};
ab w[N][4];
int visx[N];
vector<int> vec[4]; 
void init(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=3;++j){
			w[i][j].x=0; w[i][j].id=0;
		}
	}
	for(int i=1;i<=3;++i){
		visx[i]=0;
		vec[i].clear();
	}
	return ;
}
bool cmp(ab x,ab y){
	return x.x > y.x;
}
bool cmp2(int x,int y){
	return w[x][2].x-w[x][1].x > w[y][2].x-w[y][1].x;
}
inline void see_you_again(){
	cin>>n; 
	init();
	for(int i=1;i<=n;++i){
		int a,b,c;
		cin>>a>>b>>c;
		w[i][1].x=a; w[i][1].id=1;
		w[i][2].x=b; w[i][2].id=2;
		w[i][3].x=c; w[i][3].id=3;
		sort(w[i]+1,w[i]+3+1,cmp); 
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		visx[w[i][1].id]++;
		ans+=w[i][1].x; 
		vec[w[i][1].id].push_back(i);
	}
	for(int i=1;i<=3;++i){
		if(visx[i]>=n/2){
			sort(vec[i].begin(),vec[i].end(),cmp2);
			int cnt=0;
			for(int j=1;j<=visx[i]-(n/2);++j){
				ans+=w[vec[i][cnt]][2].x-w[vec[i][cnt]][1].x;
				cnt++;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		see_you_again();
	}
	return 0;
}
