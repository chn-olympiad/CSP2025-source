#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][4],b[N],xz;
bool cmp(int x,int y){
	return x>y;
}
bool xzA(){
	for(int i=1;i<=n;i++)
		if(a[i][2]!=0||a[i][3]!=0)return 0;
	return 1;
}
int dans,sum,c[4];
void dfs(int i){
	if(i>n){
		if(c[1]<=n/2&&c[2]<=n/2&&c[3]<=n/2)dans=max(dans,sum);
		return;
	}
	for(int j=1;j<=3;j++){
		sum+=a[i][j],c[j]++;
		dfs(i+1);
		sum-=a[i][j],c[j]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
		if(n<=14){
			sum=dans=0;
			dfs(1);
			printf("%d\n",dans);
			continue;
		}
		if(xzA())xz=1;
		else xz=0;
		if(xz==1){
			int ans=0;
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=b[i];
			printf("%d\n",ans);
		}else{
			sum=dans=0;
			dfs(1);
			printf("%d\n",dans);
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
