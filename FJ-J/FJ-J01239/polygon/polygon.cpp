#include<bits/stdc++.h>
using namespace std;

int a[5012],n;
long long ans=0;
void dfs(int tot,int maxn,int br,int xu){
	if(tot>maxn*2&&xu>=3&&br==n){
		ans++;
		return ;
	}
	if(br==n) return ;
	dfs(tot+a[br+1],a[br+1],br+1,xu+1);
	dfs(tot,maxn,br+1,xu);
}
void solve1(){
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(a[1],a[1],1,1);
	dfs(0,0,1,0);
	cout<<ans;
	
}
long long zxc(int xc1,int yc1){
	long long s1=1,s2=1;
	for(int i=0;i<yc1;i++) s1*=(xc1-i);
	for(int i=0;i<yc1;i++) s2*=(yc1-i);
	return s1/s2;
}
void solve2(){
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++){
		ans+=zxc(n,i);
	}
	cout<<ans%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=20) solve1();
	else solve2();
	return 0;
}

