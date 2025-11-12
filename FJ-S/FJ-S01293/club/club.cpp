#include <bits/stdc++.h>
using namespace std;
#define int long long
//My Luogu username is LuoGuRobot,please help me become a better OIer!
//I Love CCF.I Love CSP.rp++
//orz

//It's been a long day,without you my friend....
//...want to see you again....
int n,a2[10005][5],ans=0;
void dfs(int u,int cnt1,int cnt2,int cnt3,int res){
	if(u==n+1){
		ans = max(ans,res);
	}
	if(cnt1<n/2)dfs(u+1,cnt1+1,cnt2,cnt3,res+a2[u][1]);
	if(cnt2<n/2)dfs(u+1,cnt1,cnt2+1,cnt3,res+a2[u][2]);
	if(cnt3<n/2)dfs(u+1,cnt1,cnt2,cnt3+1,res+a2[u][3]);
}

struct af{
	int num,student,field;
	bool operator <(const af &W)const{
		return num > W.num;
	}
}a[100005];
void solve(){
	int vis[100005],cnt[5];
	ans = 0;
	for(int i=1;i<=100000;i++)vis[i]=0;
	for(int i=1;i<=3;i++)cnt[i]=0;
	cin >> n;
	if(n<=15){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin >> a2[i][j];
			}
		}
		dfs(1,0,0,0,0);
		cout << ans << "\n";
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin >> a[(i-1)*3+j].num;
			a[(i-1)*3+j].student = i;
			a[(i-1)*3+j].field = j;
		}
	}
	sort(a+1,a+n*3+1);
	for(int i=1;i<=n*3;i++){
		af u = a[i];
		if(!vis[u.student]&&cnt[u.field]<n/2){
			ans += u.num;
			vis[u.student] = true;
			cnt[u.field]++;
//			cout << "将"  << u.student << "分配到" << u.field << endl; 
		}
	}
	cout << ans << "\n";
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	
	int T=1;
	cin >> T;
	while(T--){
//		cout << "对于第" << T+1 << "组数据"; 
		solve();
	}
	
	return 0;
}
