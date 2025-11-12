#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+10;
int n,a[N][5],b[N],p[N],sum;
struct node{
	int a,b,c;
}c[N];
bool cmp(node a,node b){
	if(a.a == b.a){
		if(a.b == b.b) return a.c > b.c;
		else return a.b > b.b;
	}
	return a.a > b.a;
}
void dfs(int dep){
	if(dep == n){
		int ans = 0;
		int A = 0,B = 0,C = 0;
		for(int i = 1;i<=n;i++){
			if(p[i] == 1) A++;
			if(p[i] == 2) B++;
			if(p[i] == 3) C++;
		}
		if(A > n/2 || B > n/2 || C > n/2) return;
		for(int i = 1;i<=n;i++)
			ans += a[i][p[i]];
		sum = max(sum,ans);
		return;
	}
	for(int i = 1;i<=3;i++){
		p[dep+1] = i;
		dfs(dep+1);
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T; cin>>T;
	while(T--){
		cin>>n;
		int res = 0;
		int ans = 0;
		int A = 0,B = 0,C = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[i] = max(a[i][2],a[i][3]) - a[i][1];
			ans += a[i][1];
		}
		sort(b+1,b+n+1);
		for(int i = n/2+1;i<=n;i++)
			ans += b[i];
		res = max(ans,res);
		ans = 0;
		
		if(n <= 10){
			sum = 0;
			dfs(0);
			cout<<sum<<endl;
			continue;
		}
		
		for(int i = 1;i<=n;i++){
			b[i] = max(a[i][1],a[i][2]) - a[i][3];
			ans += a[i][3];
		}
		sort(b+1,b+n+1);
		for(int i = n/2+1;i<=n;i++)
			ans += b[i];
		res = max(ans,res);
		
		
		ans = 0;
		for(int i = 1;i<=n;i++){
			b[i] = max(a[i][3],a[i][1]) - a[i][2];
			ans += a[i][2];
		}
		sort(b+1,b+n+1);
		for(int i = n/2+1;i<=n;i++)
			ans += b[i];
		res = max(ans,res);
		
		ans = 0;
		for(int i = 1;i<=n;i++){
			c[i].a = a[i][1];
			c[i].b = a[i][2];
			c[i].c = a[i][3];
		}
		sort(c+1,c+n+1,cmp);
		for(int i = 1;i<=n;i++){
			if(c[i].a >= c[i].b && c[i].a >= c[i].c){
				if(A < n/2) A++,ans += c[i].a;
				else if(c[i].b >= c[i].c) B++,ans += c[i].b;
				else C++,ans += c[i].c;
			}
			else if(c[i].b >= c[i].a && c[i].b >= c[i].c){
				if(B < n/2) B++,ans += c[i].b;
				else if(c[i].a >= c[i].c) A++,ans += c[i].a;
				else C++,ans += c[i].c;
			}
			else{
				if(C < n/2) C++,ans += c[i].c;
				else if(c[i].b >= c[i].a) B++,ans += c[i].b;
				else A++,ans += c[i].a;
			}
		}
		res = max(res,ans);
		cout<<res<<'\n';
	}
	return 0;
} 
