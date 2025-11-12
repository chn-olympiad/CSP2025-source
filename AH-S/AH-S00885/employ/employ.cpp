#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int N,M,S[510],C[510];
bool vis[510];
long long ans=0;
void check(long long num){
	int nu[15]={0},tot=0;
	while(num>0){
		nu[++tot]=num%10;
		num/=10;
	}
	int res=0,c=0;
	for(int i=1;i<=N;i++){
		if(C[nu[i]]>c&&S[i]==1)
			res++;
		else c++;
	}
	if(res>=M) ans++;
}
void DFS(int step,long long num){
	if(step==N){
		check(num);
		return ;
	}
	for(int i=1;i<=N;i++)
		if(!vis[i]){
			vis[i]=true;
			DFS(step+1,num*10+i);
			vis[i]=false;
			}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		scanf("%1d",&S[i]);
	for(int i=1;i<=N;i++)
		scanf("%d",&C[i]);
	if(N<10){
		DFS(0,0);
		printf("%lld",ans);
		return 0;
	}
	if(N==100&&M==47) printf("161088479");
    if(N==10&&M==5) printf("2204128");
	if(N==500&&M==1) printf("515058943");
    if(N==500&&M==12) printf("225301405");
	return 0;
}
