#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+10;
const ll INF=998244353;
int n,a[N];
bool vis[N];
ll ans;

bool cmp(int a,int b){
	return a>b;
}

void dfs(int set,int cnt,int add,int Max){
	if(cnt>=3 && add>2*Max){
		ans++;
		ans%=INF;
	}
	for(int i=set;i<=n;i++){
		dfs(i+1,cnt+1,add+a[i],max(a[i],Max));
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
