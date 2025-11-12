#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct node{int x,y,z;}a[maxn];
bool cmp(node a,node b){return a.x>b.x;}
int n,cnt[5],mx;
int pos;
double tim,st;
void dfs(int x,int y){
	if(x==n+1||clock()-st>=tim*(pos+1)){
		mx=max(mx,y);
		return;
	}
	for(int i=1;i<=3;++i){
		if(cnt[i]==n/2) continue;
		++cnt[i];
		dfs(x+1,y+(i==1?a[x].x:(i==2?a[x].y:a[x].z)));
		--cnt[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;scanf("%d",&T);
	st=clock();
	tim=1000.0/T;
	cout<<tim<<endl;
	while(T--){
		++pos;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
		sort(a+1,a+n+1,cmp);
		if(n<=16){
			mx=cnt[1]=cnt[2]=cnt[3]=0;
			dfs(1,0);
			printf("%d\n",mx);
		}else{
			int sum=0;
			for(int i=1;i<=n/2;++i) sum+=a[i].x;
			for(int i=n/2+1;i<=n;++i) sum+=max(a[i].y,a[i].z);
			printf("%d\n",sum);
		}
	}
}
/*
zmx lsy
千万不要删这行，别问我为什么，删了会寄
*/
