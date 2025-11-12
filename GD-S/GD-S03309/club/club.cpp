#include<bits/stdc++.h>
#define ll long long
const int N=1e5+10;
using namespace std;
int n,b[N];
struct node{
	int x,y,z;
}a[N];
int mx(int xx,int yy,int zz){
	return max(xx,max(yy,zz));
}
int mi(int xx,int yy,int zz){
	return min(xx,min(yy,zz));
}
bool cmp(node p,node q){
	return p.x>q.x;
}
void solve(){
	memset(b,0,sizeof(b));
	bool A=1,B=1;
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		if(mx(a[i].x,a[i].y,a[i].z)==a[i].x) b[i]=1;
		if(mx(a[i].x,a[i].y,a[i].z)==a[i].y) b[i]=2;
		if(mx(a[i].x,a[i].y,a[i].z)==a[i].z) b[i]=3;
		if(a[i].y!=0||a[i].z!=0) A=0;
		if(a[i].z!=0) B=0;
	}
	if(n==2){
		if(b[1]!=b[2]) for(int i=1;i<=2;++i) ans+=max(a[i].x,max(a[i].y,a[i].z));
		else ans=max(a[1].x+a[1].y+a[1].z-mx(a[1].x,a[1].y,a[1].z)-mi(a[1].x,a[1].y,a[1].z)+mx(a[2].x,a[2].y,a[2].z),a[2].x+a[2].y+a[2].z-mx(a[2].x,a[2].y,a[2].z)-mi(a[2].x,a[2].y,a[2].z)+mx(a[1].x,a[1].y,a[1].z));
	}
	else if(A){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;++i) ans+=a[i].x;
	}
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	freopen("club.out","w",stdout);
	return 0;
}
