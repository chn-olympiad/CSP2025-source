#include<iostream>
using namespace std;
const int N=5e5+5;
int n,k,ans,all=1;
int sum[N];
int a[N],vis[N];
struct nod{
	int l,r;
}dif[N],u1;
bool ifgot;
void dfs(int xb,int num){//xb下标=i,num记录选的区间数 
	u1=dif[xb];
	if(vis[xb]>num)return;
	vis[xb]=num;
	ans=max(ans,num);
	//printf("%d\n",xb);
	for(int i=xb+1;i<all;i++){
		if(u1.r>=dif[i].l)continue;
		dfs(i,num+1);
	}
}
/*bool check(int i,int j){
	for(int k=1;k<=all;k++){
		u1=dif[k];
		if(u1.r==j&&u1.l>i)return 0;
	}return 1;
}*/
int main(){//异或:^ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		ifgot=0;
		for(int j=i;j<=n;j++){
			if((sum[i-1]^sum[j])==k){//填i会把区间左手去掉所以i-1
				if(!ifgot){
					//if(!check(i,j))continue;
					dif[all++]={i,j};
					ifgot=1;
					//printf("选[%d,%d]\n",i,j);
				}//else printf("去掉了[%d,%d]\n",i,j);
			}
		}
	}
	dfs(0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
