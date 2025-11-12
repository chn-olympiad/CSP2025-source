#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[5010],jh[5010][5010];
int n;
long long cnt=0;
void dfs(int bs,int h,int mx,int qd){
	if(bs>=3 && h>mx*2) cnt++;
	cnt%=998244353;
	for(int i=qd;i<=n;i++){
		dfs(bs+1,h+a[i],max(mx,a[i]),i+1);
	}
}
void solve1(){
	sort(a+1,a+n+1);
	dfs(0,0,0,1);
	cout<<cnt%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
		return 0;
	} 
	if(n<=20){
		
		solve1();
		return 0;
	}
	jh[1][0]=1,jh[1][1]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i;j++){
			jh[i][j]=jh[i-1][j-1]+jh[i-1][j];
			jh[i][j]%=998244353;
		}
	}
	for(int i=3;i<=n;i++){
		cnt+=jh[n][i];
		cnt%=998244353;
	}
	cout<<cnt;
	return 0;
}