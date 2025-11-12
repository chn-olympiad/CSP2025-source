#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=10005;
int n;
int a[N];
int ans=0;
bool cmp(int x,int y){
	return x>y;
}
bool pd(int cnt,int maxx){
	if(cnt>maxx*2)return 1;
	return 0;
}
void dfs(int t,int k,int cnt,int maxx){
	if(t>=3){
		if(pd(cnt,maxx)){
			ans=(1+ans)%mod;
		}
	}
	for(int i=k+1;i<=n;i++){
		dfs(t+1,i,cnt+a[i],max(a[i],maxx));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
} 
