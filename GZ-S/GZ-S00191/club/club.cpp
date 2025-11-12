// GZ-S00191 贵阳市南明区双龙华麟学校 徐文景 
#include<bits/stdc++.h>
using namespace std;
struct p{
	int b,c,d;
}a[100005];
int t,n,r[3],sumin,maxin,dp[100005];
void dfs(int rb,int rc,int rd,int dr,int sumint){
	if(rb>n/2||rc>n/2||rd>n/2) return;
	if(dr==n+1) {
		sumin=max(sumin,sumint);
		return;
	}
	dfs(rb+1,rc,rd,dr+1,sumint+a[dr].b);
	dfs(rb,rc+1,rd,dr+1,sumint+a[dr].c);
	dfs(rb,rc,rd+1,dr+1,sumint+a[dr].d);
}
bool cmp(p p1,p p2){
	return p1.b>p2.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		sumin=0;
		memset(a,0,sizeof(a));
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].b >> a[i].c >> a[i].d;
		}
		if(a[1].c==0&&a[1].d==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				sumin+=a[i].b;
			}
			cout << sumin << endl;
			continue;
		}
		dfs(0,0,0,1,0);
		cout << sumin << endl;
	}
	return 0;
}
