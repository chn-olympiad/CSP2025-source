#include<bits/stdc++.h>
using namespace std;
int t;
int n,k;
const int N = 1e5+10;
int a[N][4];
int b[N];
struct Student{
	int cl1,cl2,minus;
}c[N];
struct h{
	int d,u;
};
int ans;
void dfs(int u,int s,int club1,int club2,int club3){
	if(u>n){
		ans = max(ans,s);
		return;
	}
	if(club1<k) dfs(u+1,s+a[u][1],club1+1,club2,club3);
	if(club2<k) dfs(u+1,s+a[u][2],club1,club2+1,club3);
	if(club3<k) dfs(u+1,s+a[u][3],club1,club2,club3+1);
}
bool cmp1(int x,int y){
	return x>y;
}
void solveA(){
	for(int i = 1;i<=n;i++){
		b[i] = a[i][1];
	}
	sort(b+1,b+n+1,cmp1);
	for(int i = 1;i<=k;i++){
		ans+=b[i];
	}
}
bool cmp2(Student x,Student y){
	return x.minus>y.minus;
}
void solveB(){
	for(int i = 1;i<=n;i++){
		c[i].cl1 = a[i][1];
		c[i].cl2 = a[i][2];
		c[i].minus = a[i][1]-a[i][2];
	}
	sort(c+1,c+n+1,cmp2);
	for(int i = 1;i<=k;i++){
		ans+=c[i].cl1;
	}
	for(int i = k+1;i<=n;i++){
		ans+=c[i].cl2;
	}
}
void solveC(){
	for(int i = 1;i<=n;i++){
		int maxx = 0;
		for(int j = 1;j<=3;j++){
			maxx = max(maxx,a[i][j]);
		}
		ans+=maxx;
	}
}
void solve2(){
	int c1 = 0,c2 = 0,c3 = 0;
	vector<int> f[4];
	int g[N];
	for(int i = 1;i<=n;i++){
		int maxx = 0;
		for(int j = 1;j<=3;j++){
			if(maxx<a[i][j]){
				maxx = a[i][j];
				g[i] = j;
			}
		}
		if(g[i]==1) c1++;
		else if(g[i]==2) c2++;
		else c3++;
		f[g[i]].push_back(i);
	}
	if(c1<=k&&c2<=k&&c3<=k){
		for(int i = 1;i<=3;i++){
			for(auto e : f[i]){
				ans+=a[e][i];
			}
		}
	}
	else{
		h p[N];
		if(c1>k){
			for(int i = 0;i<c1;i++){
				if(a[i][2]>=a[i][3]){
					p[i].u = 2;
					p[i].d = a[i][2];
				}
				else{
					p[i].u = 3;
					p[i].d = a[i][3];
				}
			}
			
		}
		if(c2>k){
			
		}
		if(c3>k){
			
		}
	}
}
void solve(){
	cin>>n;
	bool ok2 = 1,ok3 = 1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=3;j++){
			cin>>a[i][j];
		}
		if(a[i][2]!=0) ok2 = 0;
		if(a[i][2]!=0) ok3 = 0;
	}
	k = n/2;
	if(n<=10) dfs(1,0,0,0,0);
	else if(ok2&&ok3) solveA();
	else if(ok3) solveB();
	else if(n<=200) solve2();
	else if(n<=N) solveC();
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) solve();
	return 0;
}
