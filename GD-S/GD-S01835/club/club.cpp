#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5+3;
int t,n,a[N][5],tmp[N];

int dfs(int x,int l1,int l2,int l3,int sum){
	if(l1>n/2||l2>n/2||l3>n/2)
		return -1;
	if(x==n+1)
		return sum;
	int r1=dfs(x+1,l1+1,l2,l3,sum+a[x][1]);
	int r2=dfs(x+1,l1,l2+1,l3,sum+a[x][2]);
	int r3=dfs(x+1,l1,l2,l3+1,sum+a[x][3]);
	return max(r1,max(r2,r3));
}

void task(){
	bool flag = true;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=3;++j){
			scanf("%d",&a[i][j]);
			flag&=(a[i][2]==0&&a[i][3]==0);
		}
	if(flag){
		int sum=0;
		for(int i=1;i<=n;++i){
			tmp[i] = a[i][1];
		}sort(tmp+1,tmp+n+1,greater<int>());
		for(int i=1;i<=(n>>1);++i) sum=sum+tmp[i];
		printf("%d\n",sum);
	}else{
		printf("%d\n",dfs(1,0,0,0,0));
	}
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
		task();
	return 0;
}
