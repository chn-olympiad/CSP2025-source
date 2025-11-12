#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
int T,n,p;
int dp[210][110][110][110];
struct node{
	int a,b,c;
}e[MAXN];
bool cmp1(node pre,node nxt){
	return pre.a>nxt.a;
}
void solve1(){
	int ans=0;
	sort(e+1,e+n+1,cmp1);
	for(int i=1;i<=n/2;i++){
		ans+=e[i].a;
	}
	cout<<ans<<"\n";
	return;
}
void dfs(int x,int a,int b,int c,int sum){
	if(a>n/2||b>n/2||c>n/2) return;
	if(x>n){
		p=max(p,sum);
		return;
	}
	dfs(x+1,a+1,b,c,sum+e[x].a);
	dfs(x+1,a,b+1,c,sum+e[x].b);
	dfs(x+1,a,b,c+1,sum+e[x].c);
}
void solve3(){
	p=0;
	dfs(1,0,0,0,0);
	cout<<p<<"\n";
	return;
}
void solve2(){
	int ans=0,cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		if(e[i].a>e[i].b&&e[i].a>e[i].c){
			cnt1++;
			ans+=e[i].a;
		}
		if(e[i].b>e[i].a&&e[i].b>e[i].c){
			cnt2++;
			ans+=e[i].b;
		}
		if(e[i].c>e[i].a&&e[i].c>e[i].b){
			cnt3++;
			ans+=e[i].c;
		}
	}
	cout<<ans<<"\n";
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		bool flag1=true,flag2=true;
		for(int i=1;i<=n;i++){
			cin>>e[i].a>>e[i].b>>e[i].c;
			if(e[i].b!=0) flag1=false;
			else if(e[i].c!=0) flag1=flag2=false;
		}
		if(n<=12){
			solve3();
		}
		else if(flag1){
			solve1();
		}
		else{
			solve2();
		}
	}
	return 0;
}

