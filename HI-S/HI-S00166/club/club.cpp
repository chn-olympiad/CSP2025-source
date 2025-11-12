#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[100005][3],b[100005][3],c[100005],sz[3];
int choose(int x){
	int maxx=max(a[x][0],max(a[x][1],a[x][2]));
	for(int i=0;i<3;i++){
		if(a[x][i]==maxx){
			b[++sz[i]][i]=x;
			c[x]=i;
			return i;
		}
	} 
}
int cost(int x){
	int mid=-1;
	for(int i=0;i<3;i++)if(i!=c[x])mid=max(mid,a[x][i]);
	return a[x][c[x]]-mid;
}
int costs(int x){
	int d[100005],ans=0;
	for(int i=1;i<=sz[x];i++)d[i]=cost(b[i][x]);
	sort(d+1,d+sz[x]+1);
	for(int i=1;i<=sz[x]-n/2;i++)ans+=d[i];
	return ans;
}
void solve(){
	sz[0]=0,sz[1]=0,sz[2]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&(a[i][0]),&(a[i][1]),&(a[i][2]));
		choose(i);
	}
	int ans=0;
	for(int i=0;i<3;i++)for(int j=1;j<=sz[i];j++)ans+=a[b[j][i]][i];
	for(int i=0;i<3;i++)if(sz[i]>n/2)ans-=costs(i);
	printf("%d\n",ans);
	return;
}
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
