#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
int n,t,cnt[4],b[N];
ll a[N][4];
struct A{
	int x,ch;
	ll val;
}c[N];
bool cmp(A f,A g){
	return f.val>g.val;
}
void cleanA(){
	cnt[1]=cnt[2]=cnt[3]=0;
}
void moveA(int x){
	int y,z;
	if(x==1)y=2,z=3;
	if(x==2)y=1,z=3;
	if(x==3)y=1,z=2;
	
	int m=0;
	for(int i=1;i<=n;i++){
		if(b[i]==x){
			c[++m].x=i;
			if(a[i][y]>a[i][z])c[m].ch=y;
			else c[m].ch=z;
			c[m].val=a[i][c[m].ch]-a[i][x];
		}
	}
	sort(c+1,c+m+1,cmp);
	for(int i=1;i<=m;i++){
		int p=c[i].x,ch=c[i].ch;
		b[p]=ch;
		cnt[x]--;
		if(cnt[x]<=n/2)break;
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])b[i]=1;
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])b[i]=2;
		else b[i]=3;
		cnt[b[i]]++;
	}
	for(int j=1;j<=3;j++){
		if(cnt[j]>n/2){
			moveA(j);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i][b[i]];
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		cleanA();
		solve();
	}
	return 0;
}
