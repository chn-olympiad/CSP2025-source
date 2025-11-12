#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
	int a, b, c;
}a[100005];
int n;
bool cmp1(st x, st y){
	return x.a<y.a; 
}
bool cmp2(st x, st y){
	return x.b<y.b; 
}
bool cmp3(st x, st y){
	return x.c<y.c; 
}
int maxn=0;
void dfs(int step, int as, int bs, int cs, int ans){
	if(step>n){
		maxn=max(maxn, ans);
		return ;
	}
	if(as<n/2) dfs(step+1, as+1, bs, cs, ans+a[step].a);
	if(bs<n/2) dfs(step+1, as, bs+1, cs, ans+a[step].b);
	if(cs<n/2) dfs(step+1, as, bs, cs+1, ans+a[step].c);
	return ;
}
int T;
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int a1=0, a2=0, a3=0, b10=0, b20=0, b30=0;
		maxn=0;
		for(int i=1;i<=n;i++){
			cin >> a[i].a >> a[i].b >> a[i].c;
			if(!a[i].a) b10++;
			if(!a[i].b) b20++;
			if(!a[i].c) b30++;
		}
		if(b20==n && b30==n){
			sort(a+1, a+n+1, cmp1);
			for(int i=1;i<=n/2;i++){
				a1+=a[i].a;
			}
			cout << a1 << "\n";
		}else if(b10==n && b30==n){
			sort(a+1, a+n+1, cmp2);
			for(int i=1;i<=n/2;i++){
				a2+=a[i].b;
			}
			cout << a2 << "\n";
		}else if(b10==n && b20==n){
			sort(a+1, a+n+1, cmp3);
			for(int i=1;i<=n/2;i++){
				a3+=a[i].c;
			}
			cout << a3 << "\n";
		}else{
			dfs(1, 0, 0, 0, 0);
			cout << maxn << "\n";
		}
	}
	return 0;
} 
