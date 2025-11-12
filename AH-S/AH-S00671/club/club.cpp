#include<bits/stdc++.h>
using namespace std;
int n;
bool cmp(int a,int b){
	return a>b;
}
long long a1[100005],a2[100005],a3[100005];
long long d[100005][4];
long long ans=0;
void dfs(int i,long long s,int z1,int z2,int z3){
	if(i>n){
		ans=max(ans,s);
	}
	if(z1<n/2)dfs(i+1,s+a1[i],z1+1,z2,z3);
	if(z2<n/2)dfs(i+1,s+a2[i],z1,z2+1,z3);
	if(z3<n/2)dfs(i+1,s+a3[i],z1,z2,z3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ss1=0,ss2=0,ss3=0;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&d[i][1],&d[i][2],&d[i][3]);
			a1[i]=d[i][1],a2[i]=d[i][2],a3[i]=d[i][3];
			if(d[i][1]==0){
				ss1++;
			}
			if(d[i][2]==0){
				ss2++;
			}
			if(d[i][3]==0){
				ss3++;
			}
		}
		if(ss1==n&&ss2==n){
			sort(a3+1,a3+1+n,cmp);
			int cnt=0;
			for(int i=1;i<=n/2;i++){
				cnt+=a3[i];
			}
			printf("%d\n",cnt);
			continue;
		}
		if(ss1==n&&ss3==n){
			sort(a2+1,a2+1+n,cmp);
			int cnt=0;
			for(int i=1;i<=n/2;i++){
				cnt+=a2[i];
			}
			printf("%d\n",cnt);
			continue;
		}
		if(ss3==n&&ss2==n){
			sort(a1+1,a1+1+n,cmp);
			int cnt=0;
			for(int i=1;i<=n/2;i++){
				cnt+=a1[i];
			}
			printf("%d\n",cnt);
			continue;
		}
		ans=0;
		dfs(1,0,0,0,0);
		printf("%lld\n",ans);
	}
    return 0;
}
