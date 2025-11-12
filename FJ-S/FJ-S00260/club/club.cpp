#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
	int l1,l2,l3;
 }b[100100];
ll t,n,f[5],ans = 0,m = 0;
bool cmp(node x,node y){
	return (x.l1 < y.l1);
 }
bool check(){
	for (int i = 1;i <= n;i++)
	 if (b[i].l2 != 0 || b[i].l3 != 0) return false;
	return true;
 }
void dfs(int x){
	if (x == n + 1) {ans = max(ans,m);;return;}
	for (int i = 1;i <= 3;i++)
	 if (f[i] < n / 2){
		 if (i == 1) m += b[x].l1;
		 if (i == 2) m += b[x].l2;
		 if (i == 3) m += b[x].l3;
		 f[i]++;
		 dfs(x + 1);
		 f[i]--;
		 if (i == 1) m -= b[x].l1;
		 if (i == 2) m -= b[x].l2;
		 if (i == 3) m -= b[x].l3; 
	  }
 }
void solve1(){
	t--,ans = -1,m = 0;
	memset(f,0,sizeof(f));
	dfs(1);
 }
void solve2(){
	ans = 0;
	sort(b + 1,b + 1 + n,cmp);
	for (int i = 1;i <= n / 2;i++) ans += b[i].l1;
 }
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t > 0){
		cin>>n;
		for (int i = 1;i <= n;i++) cin>>b[i].l1>>b[i].l2>>b[i].l3;
		if (n <= 30) solve1();
		if (check()) solve2();
		cout<<ans<<endl;
	 }
	return 0;
 }
