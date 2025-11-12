#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
bool s[maxn];
int a[maxn];
int n;
int cnt;
void check(){
	int sum=0,m=0,g=0;
	for(int i=1;i<=n;i++){
		if(s[i]){
			m=max(m,a[i]);
			sum+=a[i];
			g++;
		}
	}
	if(g<3) return;
	if(sum>m*2) cnt=(cnt+1)%998244353;
}
void dfs(int w){
	if(w==n+1){
		check();
		return;
	}
	s[w]=0;
	dfs(w+1);
	s[w]=1;
	dfs(w+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);
	cout<<cnt;
}
