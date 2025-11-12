#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,ans=0;
int a[5010];
bool vis[5010];
void dfs(int num,int Maxx,int sum,int bian){
	if(bian>2){
		if(sum>Maxx*2){
			ans=(ans+1)%Mod;
		}
	}
	for(int i=num+1;i<=n;i++){
		if(a[i]==0) continue;
		if(!vis[i]){
			vis[i]=1;
			if(Maxx<a[i]){
				dfs(i,a[i],sum+a[i],bian+1);
			}
			else dfs(i,Maxx,sum+a[i],bian+1);
			vis[i]=0;
		}
	}
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	bool fl=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=1&&a[i]!=0){
			fl=1;
			break;
		}
	}
	if(fl==0){
		printf("0");
		return 0;
	}
	dfs(0,0,0,0);
	printf("%d",ans);
	return 0;
}