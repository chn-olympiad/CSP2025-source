#include<bits/stdc++.h>
using namespace std;
int N,K,A[500010];
int B[500010][25],cnt[500010];
bool vis[500010];
int st[500010][25];
int Kf[25],tot;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&N,&K);
	int flag=1,flag2=1;
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
		if(A[i]!=1)
			flag=0;
		if(A[i]>1) flag2=0;
		int x=A[i];
		if(x==0) B[i][cnt[i]++]=0;
		while(x>0){
			B[i][cnt[i]++]=x%2;
			x/=2;
		}
	}
	if(flag){
		printf("%d",N/2);
		return 0;
	}
	if(flag2){
		int ans=0;
		if(K==1){
			for(int i=1;i<=N;i++)
				if(A[i]==K&&!vis[i]){
					ans++;
					vis[i]=true;
				}
			}
		else{
			for(int i=1;i<=N;i++)
				if(A[i]==K&&!vis[i]){
					ans++;
					vis[i]=true;
				}
				else if(A[i]==1-K&&i<N&&A[i+1]==1-K&&!vis[i]&&!vis[i+1]){
					ans++;
					vis[i]=true;
					}
			}
		printf("%d",ans);
		return 0;
	}
	if(K==0) Kf[tot++]=0;
	while(K>0){
		Kf[tot]=K%2;
		K/=2;
		tot++;
	}
	for(int i=1;i<=N;i++){
		for(int j=0;j<25;j++){
			if(B[i][j]==Kf[j])
				st[i][j]=1;
			st[i][j]+=st[i-1][j];
			}
		}
	int id=1,ans=0;
	for(int i=1;i<=N;i++){
		for(int j=id;j<=i;j++){
			bool flag=true;
			for(int d=0;d<25;d++)
				if((st[i][d]-st[j-1][d]+2)%2==0){
					flag=false;
					break;
				}
			if(flag){
				ans++;
				id=i+1;
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
