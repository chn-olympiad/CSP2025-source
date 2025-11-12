#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int N,A[5010],ans;
bool vis[15];
void finish(int step,int Max,int sum,int begin){
	if(step>=3&&step<=N&&Max*2<sum)
		ans++;
	if(step==N+1) return ;
	for(int i=begin;i<=N;i++){
		if(!vis[i]){
			vis[i]=true;
			finish(step+1,max(Max,A[i]),A[i]+sum,i+1);
			vis[i]=false;
			}
		}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&N);
	bool flag=true;
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
		if(A[i]!=1) 
			flag=false;
	}
	if(flag){
		long long ans=0,res=N*(N-1),c=1*2;
		for(int i=3;i<=N;i++){
			res=(res*(N-i+1))%Mod;
			c=(c*i)%Mod;
			ans=(ans+res/c)%Mod;
			}
			printf("%lld",ans);
		}
	else{
		finish(0,0,0,1);
		printf("%d",ans%Mod);
		return 0;
	}
	return 0;
}
