//#pragma GCC optimize(3)
#include<iostream>
#define int unsigned long long
#define cnt ccf
#define ans j0
#define cnt3 y0
using namespace std;
constexpr int maxn=2e5+5;
int t,n,a[maxn][4],ans,cnt[4],reut;
void dfs(int i){
	if(i==n+1){
		reut=max(reut,ans);
		return;
	}
	for(int j=1;j<=3;j++){
		if(cnt[j]<(n/2)){
			cnt[j]++;
			ans+=a[i][j];
			dfs(i+1);
			ans-=a[i][j];
			cnt[j]--;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		reut=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}dfs(1);
		cout<<reut<<'\n';
	}
		

	return 0;
}















/*
杜子德爷爷用百元大钞击落洛谷服务器
刚从捐款活动回来的杜子德爷爷全然不顾身体的疲惫，【数据删除】

“但是有些【数据删除】，像洛谷，纵容OIer反对CCF的【数据删除】事业！【数据删除】 
杜子德爷爷从地上拣起一块石子，向天上一掷，顿时，天上发出一阵耀眼的火光。
“这就是洛谷的服务器，【数据删除】
我们D队的成员都为有杜子德爷爷这样的NOI主席感到自豪 
*/
