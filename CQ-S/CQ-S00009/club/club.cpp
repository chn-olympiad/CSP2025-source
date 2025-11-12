#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=1e5+5;
int T,n,ans;
struct node{
	int a,b,c;
}a[N],c[N];
inline bool cmp(node x,node y){
	return x.a-x.b>y.a-y.b;
}
inline void dfs(int x,int now,int a1,int b1,int c1){
	if(x==n+1){
		ans=max(now,ans);
		return;
	}
	if(a1!=n/2)dfs(x+1,now+a[x].a,a1+1,b1,c1);
	if(b1!=n/2)dfs(x+1,now+a[x].b,a1,b1+1,c1);
	if(c1!=n/2)dfs(x+1,now+a[x].c,a1,b1,c1+1);
	return;
}
inline void solve(){
	cin>>n;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
	if(n<200){
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
		return;
	}	
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(i<=n/2)ans+=a[i].a;
		else ans+=max(a[i].b,a[i].c);
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)solve();
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
