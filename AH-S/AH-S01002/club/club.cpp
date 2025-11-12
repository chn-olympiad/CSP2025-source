#include<bits/stdc++.h>
using namespace std;
const int n1=1e5+5;
int T,n,ans=-1,c[4],s[n1],ad,cnt,sx;
bool v[n1];
int a1[n1],a2[n1],a3[n1],tt[4];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int i,int sum,int c1,int c2,int c3){
	if(i>n){
		ans=max(ans,sum);
		return;
	}
	if(c1<sx) dfs(i+1,sum+a1[i],c1+1,c2,c3);
	if(c2<sx) dfs(i+1,sum+a2[i],c1,c2+1,c3);
	if(c3<sx) dfs(i+1,sum+a3[i],c1,c2,c3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		sx=n/2;
		ans=0;
		memset(v,0,sizeof(v));
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		}
		else{
			sort(a1+1,a1+1+n,cmp);
			sort(a2+1,a2+1+n,cmp);
			sort(a3+1,a3+1+n,cmp);
			for(int i=1;i<=sx;i++) ans+=a1[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}
