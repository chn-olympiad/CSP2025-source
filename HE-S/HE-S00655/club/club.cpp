#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
constexpr int INF = 1e9;
struct student{
	int val[4], id;
	int fail[4][4];
	int now;
	int nxt;
	int getnxt(){
		int maxfail = -INF, failpos = -1;
		for(int i = 1;i <= 3;i++){
			if(fail[now][i] >= maxfail && i != now){
				failpos = i;
				maxfail = fail[now][i];
			}
		}
		return failpos;
	}
	
	student(){
		memset(val,0,sizeof val);
		memset(fail,0,sizeof fail);
	}
	
	void init(){
		now = 0;
		for(int i = 1;i <= 3;i++){
			if(val[i] > val[now]) now = i;
			
		}
		for(int i = 1;i <= 3;i++){
			for(int j = 1;j <= 3;j++){
				fail[i][j] = val[j] - val[i];
			}
		}
		nxt = getnxt();
	}
	
	bool operator<(const student other) const{
		return fail[now][nxt] < other.fail[other.now][other.nxt];
	}
};
int n;
int a[maxn][4];
void slove(){
	priority_queue<student> pq[4];
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		student x;
		for(int j = 1;j <= 3;j++){
			x.val[j] = a[i][j];
		}
		x.id = i;
		x.init();
		pq[x.now].push(x);
	}
	int limit = n/2;
	while(1){
		bool flag = true;
		for(int i = 1;i <= 3;i++){
			if((int)pq[i].size() > limit){
				flag = false;
				auto x = pq[i].top();
				pq[i].pop();
				assert(x.nxt != x.now);
				//cout<<"fail"<<" "<<x.val[x.now]<<" "<<x.now<<"->"<<x.nxt<<endl;
				x.now = x.nxt;
				x.getnxt();
				pq[x.now].push(x);
			}
		}
		if(flag) break;
	}
	int ans = 0;
	for(int i = 1;i <= 3;i++){
		while(!pq[i].empty()){
			auto x = pq[i].top();
			pq[i].pop();
			ans += x.val[x.now];
		}
	}
	cout<<ans<<endl;
	return;
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		slove();
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
