#include<bits/stdc++.h>
#define int long long
#define x first
#define y second
using namespace std;
const int N=2e6+10,inf=0x3f3f3f3f,mod=1e9+7;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef long long ll;
/*

*/
int n,a[N][3],ans,chkA,chkB;
int dfs(int x,int c1,int c2,int c3,int sum){
	if(x==n+1) return sum;
	int res=0;
	if(c1<n/2) res=max(res,dfs(x+1,c1+1,c2,c3,sum+a[x][1]));
	if(c2<n/2) res=max(res,dfs(x+1,c1,c2+1,c3,sum+a[x][2]));
	if(c3<n/2) res=max(res,dfs(x+1,c1,c2,c3+1,sum+a[x][3]));
	return res;
}
void Case0(){cout<<dfs(1,0,0,0,0)<<"\n";}
int CA_t[N];
void CaseA(){
	for(int i=1;i<=n;i++) CA_t[i]=a[i][1];
	sort(CA_t+1,CA_t+n+1);
	for(int i=n;i>n/2;i--) ans+=CA_t[i];
	cout<<ans<<"\n"; 
}
pii p[N];
void CaseB(){
	priority_queue<int> q; int cnt=0;
	for(int i=1;i<=n;i++) p[i]={a[i][1],a[i][2]};
	sort(p+1,p+n+1);
	for(int i=n;i;i--) {
		if(cnt==n/2){
			int top=q.top();
			if(p[i].x-p[i].y+top<0){
				ans+=p[i].y;
				continue;
			}
			ans+=p[i].x+top,q.pop(),q.push(p[i].y-p[i].x);
		}
		else ans+=p[i].x,q.push(p[i].y-p[i].x),++cnt;
	}
	cout<<ans<<"\n";
}
void mian(){
	cin>>n; ans=0,chkA=chkB=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++) cin>>a[i][j];
		if(a[i][2]) chkA=0;
		if(a[i][3]) chkB=0;
	}
	if(chkA&&chkB) CaseA();
	else if(chkB) CaseB();
	else if(n<=10) Case0();
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T; cin>>T;
	while(T--) mian();
	return 0;
}
