#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005],dx[500005],maxn=0,n,m,z;
bool flag=true;
struct xian{
	int l,r;
};
vector<xian> v;
bool cmp(xian x,xian y){
	if(x.l==y.l){
		return x.r<y.r;
	}
	else return x.l<y.l;
} 
int main(){
	//printf("1");
	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&dp[i][i]);
		z+=dp[i][i];
		if(dp[i][i]!=1&&dp[i][i]!=0) flag=false;
		if(dp[i][i]==m){
			xian z;
			z.l=i;
			z.r=i;
			v.push_back(z);
		}
	}
	if(flag){
		printf("%d",z);
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			dp[j][j+i-1]=dp[j][j+i-2]^dp[j+i-1][j+i-1];
			if(dp[j][j+i-1]==m){
				xian z;
				z.l=j;
				z.r=j+i-1;
				v.push_back(z);
			}
			//printf("%d ",dp[j][j+i-1]);
		}
		//printf("\n");
	}
	sort(v.begin(),v.end(),cmp);
	memset(dx,-1,sizeof(dx));
	dx[1]=0;
	for(int i=0;i<v.size();i++){
		if(dx[v[i].l]!=-1) continue;
		else{
			for(int j=1;j<v[i].l;j++){
				dx[v[i].r]=max(dx[v[i].r],dx[j]+1);
			}
			//dx[v[i].r]++;
			maxn=max(dx[v[i].r],maxn);
		}
	}
	printf("%d",maxn);
}
