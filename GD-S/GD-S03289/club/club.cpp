#include <bits/stdc++.h>
using namespace std;
long long t,n,maxx=0,a[100001][4];
void dfs(int k,long long w,int s1,int s2,int s3){
	if(k>n){
		if(w>maxx)maxx=w;
		return;
	}
	if(s1<n/2)dfs(k+1,w+a[k][1],s1+1,s2,s3);
	if(s2<n/2)dfs(k+1,w+a[k][2],s1,s2+1,s3);
	if(s3<n/2)dfs(k+1,w+a[k][3],s1,s2,s3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		maxx=0;
		long long ans=0,cha[100001],e=0,f=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
			cha[i]=abs(a[i][1]-a[i][2]);
		}
		if(n<=30){
			dfs(1,0,0,0,0);
			printf("%lld\n",maxx);
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i][1]>a[i][2])ans+=a[i][1],e++;
				else ans+=a[i][2],f++;
			}
			sort(cha+1,cha+n+1);
			for(int i=1;i<=max(e-n/2,f-n/2);i++)ans-=cha[i];
			printf("%lld\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
