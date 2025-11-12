#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int T,n,a[MAXN][5],maxx;
long long ans;
struct node{
	int i,f;
	node(){
	}
	node(int a,int b){
		i=a,f=b;
	}
};
vector<node>b[5];
int f(int x,int y){
	if(y==1)return max(a[x][2],a[x][3]);
	else if(y==2)return max(a[x][1],a[x][3]);
	else return max(a[x][1],a[x][2]);
}
bool cmp(node c,node b){
	int x=f(c.i,c.f),y=f(b.i,b.f);
	return a[c.i][c.f]-x>a[b.i][b.f]-y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=3;i++)b[i].clear();
		for(int i=1;i<=n;i++){
			maxx=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>a[i][maxx])maxx=j;
			}
			b[maxx].push_back({i,maxx});
			ans+=a[i][maxx];
		}
		for(int i=1;i<=3;i++){
			if((int)b[i].size()>n/2){
				sort(b[i].begin(),b[i].end(),cmp);
				int l=b[i].size();
				for(int j=n/2;j<l;j++){
					ans-=a[b[i][j].i][b[i][j].f]-f(b[i][j].i,b[i][j].f);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}