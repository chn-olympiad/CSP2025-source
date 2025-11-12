#include<bits/stdc++.h>
#define mod 998244353  
using namespace std;
int n,a[5090],cnt,ans[5090];
bool used[5090];
void dfs(int num,int step,int sum,int maxn){
	if(sum>maxn*2&&step>2){
		cnt++;
		cnt%=mod;
		//for(int i=1;i<=step;i++) printf("%d ",ans[i]);
		//printf("\n");
	}
	if(step>n) return;
	for(int i=num+1;i<=n;i++){
		if(!used[i]){
			used[i]=true;
			ans[step+1]=a[i];
			maxn=max(maxn,a[i]);
			dfs(i,step+1,sum+a[i],maxn);
			used[i]=false;
		}
	}
}
int main(){
	//别注释freopen！
	//多测要清空！
	//做完检查！
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		used[i]=true;
		ans[1]=a[i];
		dfs(i,1,a[i],a[i]);
		used[i]=false;
	}
	cnt%=mod;
	printf("%d",cnt);
	return 0;
}
//不管时间复杂度了反正40pts了 
//expect:100+100+(10,60)+(40,70)=(250,330)
//1=应该稳了，和去年难度差不多 
