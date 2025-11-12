#include<bits/stdc++.h>
using namespace std;
int a[15],b[15],c[15],sum,x[15],y[15],z[15],n,mx[15],my[15],mz[15],t1=1,t2=1,t3=1,tt1,tt2,tt3,t;
void dfs(int i,int ss){
	if(i>n){
		if(ss>sum && t1-1<=n/2 && t2-1<=n/2 && t3-1<=n/2){
			sum=ss;
		}
		return;
	}
	t1++;
	dfs(i+1,ss+a[i]);
	t1--;
	t2++;
	dfs(i+1,ss+b[i]);
	t2--;
	t3++;
	dfs(i+1,ss+c[i]);
	t3--;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		t1=1,t2=1,t3=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
	dfs(1,0);
	printf("%d\n",sum);
}
	return 0;
}
