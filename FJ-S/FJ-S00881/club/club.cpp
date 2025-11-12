#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int g[6][3]={
{0,1,2},
{0,2,1},
{1,0,2},
{1,2,0},
{2,0,1},
{2,1,0},
};
int t;
int n,x,y;
ll ans=0;
int top[3];
int b[200001];
int a[200001][3];
struct Node{
	int i;
	int v;
}st[3][200001];

bool cmp(const Node &A,const Node &B){
	return A.v>B.v;
}

void solve(int p){
	if(top[p]<=n/2)return;
	sort(st[p]+1,st[p]+top[p]+1,cmp);
	if(p==0)x=1,y=2;
	else if(p==1)x=0,y=2;
	else x=0,y=1;
	for(int i;top[p]>n/2;){
		i=st[p][top[p]].i;
		if(top[x]<n/2){
			if(top[y]<n/2){
				if(a[i][x]>a[i][y]){
					st[x][++top[x]].i=i;
					st[x][top[x]].v=a[i][x];
				}else{
					st[y][++top[y]].i=i;
					st[y][top[y]].v=a[i][y];
				}
			}
		}else{
			if(top[y]<n/2){
				st[y][++top[y]].i=i;
				st[y][top[y]].v=a[i][y];
			}
		}
		--top[p];
	}
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	srand(time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		bool A=true;
		ans=0ll;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][1]!=0||a[i][2]!=0)A=false;
		}
		if(A){
			for(int i=1;i<=n;i++){
				b[i]=a[i][0];
			}
			sort(b+1,b+n+1);
			for(int i=n/2+1;i<=n;i++){
				ans+=1ll*b[i]; 
			}
			printf("%lld\n",ans);
			continue;
		}
		ans=0ll;
		for(int kind=0;kind<6;kind++){
			memset(st,0,sizeof(st));
			memset(top,0,sizeof(top));
			for(int i=1;i<=n;i++){
				if((a[i][0]>a[i][1])&&(a[i][0]>a[i][2])){
					st[0][++top[0]].i=i;
					st[0][top[0]].v=a[i][0];
				}else if(a[i][1]>a[i][2]){
					st[1][++top[1]].i=i;
					st[1][top[1]].v=a[i][1];
				}else{
					st[2][++top[2]].i=i;
					st[2][top[2]].v=a[i][2];
				}
			}
			solve(g[kind][0]);
			solve(g[kind][1]);
			solve(g[kind][2]);
			ll sum=0;
			for(int i=0;i<3;i++){
				for(int j=1;j<=top[i];j++){
					sum+=1ll*st[i][j].v; 
				}
			}
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
