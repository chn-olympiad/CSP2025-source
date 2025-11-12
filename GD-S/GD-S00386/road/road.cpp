#include<bits/stdc++.h>//40pts
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define INFF 0x3f
#define INF 0x3f3f3f3f
const int N=1e3+10,M=1e7+10;
int p[N];
int find(int x){
	if(p[x]!=x) return p[x]=find(p[x]);
	return p[x];
}
struct stu{
	int a,b,c;
}edge[M];
ll ans;
int w[N][N];
int c[20][N];
int b[20];
bool cmp(stu p1,stu p2){
	return p1.c<p2.c;
}
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) p[i]=i;
	memset(w,INFF,sizeof(w));
	int x,y,z;
	if(k==0){//1-4
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			if(x>y){//保证x<y 
				int t;
				t=y;
				y=x;
				x=t;
			}
			edge[i]={x,y,z};
		}
		sort(edge+1,edge+m+1,cmp);
		for(int i=1;i<=m;i++){
			int a=edge[i].a,b=edge[i].b,c=edge[i].c;
			if(find(a)!=find(b)){
				int pa=find(a),pb=find(b);
				p[pa]=pb;
				ans+=c;
			}
		}
		cout<<ans;
		return 0;
	}
	
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(z>=w[x][y]||z>=w[y][x]) continue;
		if(x>y){//保证x<y 
			int t;
			t=y;
			y=x;
			x=t;
		}
	//	edge[i]={x,y,z};
		w[x][y]=z;
	}
	for(int i=1;i<=k;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	int cnt=1;
	for(int l=1;l<=k;l++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				w[i][j]=min(w[i][j],c[l][i]+c[l][j]);//xingzhi A
				edge[cnt++]={i,j,w[i][j]};
			}
		}
	}
	cnt--;
	sort(edge+1,edge+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int a=edge[i].a,b=edge[i].b,c=edge[i].c;
		if(find(a)!=find(b)){
			int pa=find(a),pb=find(b);
			p[pa]=pb;
			ans+=c;
		}
	}
	cout<<ans;
	return 0;
}

