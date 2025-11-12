#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct Point{
	int val,id,y;
};
int t,n,a[N][5],col[4],vis[N],ans;
vector <Point> e[4];
bool cmp(Point x,Point y){
	return x.y-x.val>y.y-y.val;
}
void work(){
	cin >> n;memset(vis,0,sizeof(vis));ans=0;
	for(int i = 1;i <= 3;i++)e[i].clear();
	for(int i = 1;i <= n;i++)for(int j = 1;j <= 3;j++)cin >> a[i][j];
	for(int i = 1;i <= n;i++){
		if(a[i][1]>=max(a[i][2],a[i][3])){
			ans+=a[i][1];
			e[1].push_back((Point){a[i][1],i,max(a[i][2],a[i][3])});
			//cout << "insert1" << "\n"; 
		}else if(a[i][2]>=max(a[i][1],a[i][3])){
			ans+=a[i][2];
			e[2].push_back((Point){a[i][2],i,max(a[i][1],a[i][3])});
		}else{
			ans+=a[i][3];
			e[3].push_back((Point){a[i][3],i,max(a[i][1],a[i][2])});
		}
	}//cout <<"wyt:" <<  ans << "\n";
	int maxn=0,id=0;
	for(int i = 1;i <= 3;i++)maxn=max(maxn,(int)e[i].size());
	if(maxn>n/2){//
		for(int i = 1;i <= 3;i++)if(e[i].size()>n/2)id=i;//输入文本 
		sort(e[id].begin(),e[id].end(),cmp);
	//	cout << e[id][0].val << " " << e[id][0].y << "\n";
		for(int i = 0;i < e[id].size()-n/2;i++)ans-=e[id][i].val-e[id][i].y;
		cout << ans << "\n";
	}else{
		cout << ans << "\n";
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--)work();
	return 0;
}
//点击输入文本
//糟了，假了
//发现这个n/2很耐人寻味
//毕竟其他两个就可以随便放了
//想到了
//首先先考虑不管人数限制做一个贪心，这样>=answer
//然后考虑踢人
//发现实际上踢人到n/2就可以了
//这样对吗
//让我烧烤一下
//为啥不对 
