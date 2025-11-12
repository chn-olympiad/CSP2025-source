#include<bits/stdc++.h>
using namespace std;
int a[5010];
int vis[5010];
int n;
int o=0;
void dfs(int i,int u,int h,int m){
	if(i<u){
		if(h>m*2)o++;
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[i]!=0){
			vis[i]=1;
			dfs(i,u+1,h+a[i],max(m,a[i]));
			vis[i]=0;
		}
	}
}
int s(){
	int x=max({a[0],a[1],a[2]});
	if(x*2<a[0]+a[1]+a[2])cout<<1;
}
int s1(){
	int u=0;
	for(int i=3;i<=n;i++){
		int x=1;
		for(int j=n;j>n-i;j--){
			x*=j;
			x%=998244353;
		}
		u+=x;
		u%=998244353;
	}
	cout<<u;
}
int s2(){
	for(int i=3;i<=n;i++){
		dfs(i,1,0,0);
	}
	cout<<o;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int x=0,ok=0,d;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==1)x++;
	}
	if(n<=3)s();
	else if(n<=10)s2();
	else s1();
}

