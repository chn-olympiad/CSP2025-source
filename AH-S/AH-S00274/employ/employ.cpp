#include<bits/stdc++.h>
#define mo 998244353
using namespace std;
int n,m;
char chs[505];
int s[505];
int c[505];
int p[505];
bool mark[505];
bool fq[505];
int ans=0;
void dfs(int k){
	if(k==n+1){
		for(int i=1;i<=n;i++) fq[i]=0;
		int fqs=0, sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]==1&&!fq[p[i]]){
				sum++;
			}else{
				fq[p[i]]=1;
				fqs++;
				for(int j=i+1;j<=n;j++){
					if(fqs>=c[p[j]]) {
						fq[p[j]]=1;
						fqs++;
					} 
				}
			}
		}
		if(sum>=m) {
			ans=(ans+1)%mo;
			//printf("%d:",sum);
			//for(int i=1;i<=n;i++){
			//	printf("%d ",p[i]);
			//}
			//puts("");
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(mark[i]==0){
			mark[i]=1;
			p[k]=i;
			dfs(k+1);
			mark[i]=0;
			p[k]=0;
		}
	}
}
int zuheans[505][505];
int zuhe(int nn,int mm){
	if(zuheans[nn][mm]!=0) return zuheans[nn][mm];
	if(mm==nn||mm==0) return 1;
	zuheans[nn][mm]=(zuhe(nn-1,mm)+zuhe(nn-1,mm-1))%mo;
	return zuheans[nn][mm];
}
bool checkA(){
	for(int i=1;i<=n;i++){
		if(s[i]==0) return 0;
	}
	return 1;
}
void solveA(){
	
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",chs+1);
	for(int i=1;i<=n;i++){
		s[i]=chs[i]-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	//if(checkA()){
		//solveA();
		//return 0;
	//}
	dfs(1);
	printf("%d",ans);
	return 0;
}
/*
 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`
 abcdefghijklmnopqrstuvwxyz{|}~
*/
