#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
inline int in(){
	int f=1,k=0;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
int n;
int a[5010],sw[5005];
int cnt=0;
void dfs(int i,int st,int sum,int maxn){
	if(st==1){
		sum+=a[i];
		maxn=i;
		if(sum>a[maxn]*2) 
			cnt++;
	}
	if(i==n) return;
	dfs(i+1,0,sum,maxn);
	dfs(i+1,1,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	n=in();
	for(int i=1;i<=n;i++) {
		a[i]=in();
	}
	sort(a+1,a+n+1);
	dfs(1,1,0,1);
	dfs(1,0,0,1);
	cout << cnt%998244353;
	return 0;
} 
