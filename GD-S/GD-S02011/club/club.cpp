#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node{
	int id,x;
	operator < (const node& a){
		return x < a.x;
	}
};
int n,csum[5],ans;
int ayl[100005][5];
priority_queue<node> mfall[5][5];
int fallid[5][5];
int chose[100005]; 
void dfs(int x,int sum,int a,int b,int c){
	if (a > n/2 || b > n/2 || c > n/2) return;
	if (x == 0){
		ans = max(ans,sum);
	}
	dfs(x-1,sum+ayl[x][1],a+1,b,c);
	dfs(x-1,sum+ayl[x][2],a,b+1,c);
	dfs(x-1,sum+ayl[x][3],a,b,c+1);
}
int main(){
	int t;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> t;
	while (t--){
		ans = 0;
		cin >> n;
		memset(ayl,0,sizeof(ayl));
		for (int i = 1;i <= n;i++){
			cin >> ayl[i][1] >> ayl[i][2] >> ayl[i][3];
		}
		dfs(n,0,0,0,0);
		cout << ans << endl;
	}
		
//	bool flag = true;
//	for (int i = 1;i <= n;i++){
// 	int maxed = 0,maxid;
//		for (int j = 1;j <= 3;j++){
//			if (ayl[i][j] > maxed){
//				maxed = ayl[i][j];
//				maxid = j;
//			}
//		}
//		chose[i] = maxid;
//		csum[maxid]++;
//		if (!(csum[1] > n/2 || csum[2] > n/2 || csum[3] > n/2)){
//			for (int y = 1;y <= 3;y++){
//			    mfall[maxid][y].push(node{i,ayl[i][maxid]-ayl[i][y]});
//			}
//			continue;
//		}
//		csum[maxid]--;
//		int minpush=0x3f3f3f3f,pushid=0;
//		for (int i = 1;i <= 3;i++){
//			if (mfall[maxid][i].top().x < minpush){
//				minpush = mfall[maxid][i].top().x; 
//				pushid = mfall[maxid][i].top().id;
//			} 
//		}cout << minpush << ":>" << pushid << endl;
//	}
}
