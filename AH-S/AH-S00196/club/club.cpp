#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=2e9+7;
int n,m;
int a[N][3];
int b[N];
bool cmp(int x,int y){return x>y;}
void init(){
	scanf("%d",&n),m=n>>1;
	for(int i=1,x,y,z;i<=n;i++)
	for(int j=0;j<3;j++)scanf("%d",&a[i][j]);
}
int Ans=0,res=0;
void solve(int id){
	res=0;
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=0;j<3;j++)
			if(j!=id)mx=max(a[i][j],mx);
		b[i]=a[i][id]-mx;
		res+=mx;
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=m;i++)res+=b[i];
	Ans=max(Ans,res);
}
int cnt[3];
void work(){
	Ans=0;
	memset(cnt,0,sizeof cnt);
	for(int i=1;i<=n;i++){
		int mx=0,mxp=0;
		for(int j=0;j<3;j++)if(a[i][j]>=mx)mx=a[i][j],mxp=j;
		Ans+=mx;
		cnt[mxp]++;
	}
	bool fl=0;
	for(int j=0;j<3;j++)if(cnt[j]>m)fl=1;
	if(fl)Ans=0;
	for(int j=0;j<3;j++)solve(j);
	printf("%d\n",Ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=0;
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	return 0;
}