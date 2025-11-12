#include<iostream>
const int N = 5000 + 5;
int a[N],n,ans;
bool f[N],flag = 1;
void dfs(int dep,int sum,int mx,int use){
	if(dep > n){
		if(mx * 2 < sum && use > 2) ans ++;
		return;
	}
	dfs(dep + 1,sum,mx,use);
	dfs(dep + 1,sum + a[dep],std::max(mx,a[dep]),use + 1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",a + i);
		flag &= (a[i] == a[1]);
	}
	if(flag){
		int c_n_2 = n * (n - 1) / 2;
		int c_n_1 = n;
		printf("%d\n",(1 << n) - c_n_2 - c_n_1 - 1);
	}else if(n <= 20){
		dfs(1,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
