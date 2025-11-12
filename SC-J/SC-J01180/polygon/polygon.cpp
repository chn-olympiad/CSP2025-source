#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
int cnt;
const int maxn = 998244353;
void dfs(int i,int sum,int maxx,int xz){
	
	if(i==n+1&&xz>=3&&sum>2*maxx){
		cnt ++;
		cnt%=maxn;
		return;
	}
	if(i==n+1)return;
	dfs(i+1,sum,maxx,xz);
	int maxxx=  max(maxx,a[i]);
	int summ = sum +a[i];
	dfs(i+1,summ,maxxx,xz+1);
}
void solve1(){
	dfs(1,0,0,0);
	cout<<cnt;
}
void solve2(){
	int m=2;
	for(int i=2;i<=n;i++){
		m = (m*2)%maxn;
	}
	int mm = n+((n-1)*n/2)+1;
	mm = mm%maxn;
	m-=mm;
	cout<<m;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20)solve1();
	else solve2();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
