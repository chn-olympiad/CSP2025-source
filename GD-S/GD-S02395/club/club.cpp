#include <iostream>
#include <cstdio>
#include <algorithm>
const int N=1e5+100;
using namespace std;

int t;
int n=0,a[N],b[N],c[N],tag=1,sum=0;

bool cmp(const int &a,const int &b){
	return a>b;
}

void dfs(int id,int ai,int bi,int ci,int su){
	if(id==n+1) sum=max(sum,su);
	if(ai<n/2)dfs(id+1,ai+1,bi,ci,su+a[id]);
	if(bi<n/2)dfs(id+1,ai,bi+1,ci,su+b[id]);
	if(ci<n/2)dfs(id+1,ai,bi,ci+1,su+c[id]);
}

void solve(){
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",a+i,b+i,c+i);
		if(b[i]||c[i])tag=0;
	}
	if(tag){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)sum+=a[i];
		printf("%d\n",sum);
	}
	else {
		dfs(0,0,0,0,0);
		printf("%d\n",sum);
	} 
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
