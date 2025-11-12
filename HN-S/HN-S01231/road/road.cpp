#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int cnt=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=!f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return ((f==0)?cnt:-cnt);
}

void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}

int n,m,k;

int x,y,w;

struct node{
	int x,y,w,f;
};

vector<node> e;

bool cmp(node a,node b){
	return a.w<b.w;
}

int fa[10005];

int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]);
}

void unite(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y)fa[x]=y;
}

bool vis[20005];

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=m;i++){
		cin>>x>>y>>z;
		e.push_back(node{x,y,z,-1});
	}
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(e.begin(),e.end(),cmp);
		int l=e.size(),ans=0,cnt=0;
		for(int i=0;i<l;i++){
			int x=e[i].x,y=e[i].y,w=e[i].w;
			if(get(x)!=get(y)){
				unite(x,y);
				cnt++;
				ans+=w;
				if(cnt>=n-1){
					cout<<ans<<'\n';
					return 0;
				}
			}
		}
	}else{
		bool f=0;
		for(int i=1,c;i<=k;i++){
			cin>>c;
			if(c>0)f=1;
			for(int j=1,x;j<=n;j++){
				cin>>x;
				e.push_back(node{n+i,j,x,n+i});
			}
		}
		if(f==0){
			for(int i=1;i<=n+k;i++)fa[i]=i;
			sort(e.begin(),e.end(),cmp);
			int l=e.size(),ans=0,cnt=0;
			for(int i=0;i<l;i++){
				int x=e[i].x,y=e[i].y,w=e[i].w,f=e[i].f;
				if(get(x)!=get(y)){
					unite(x,y);
					cnt++;
					ans+=w;
					if(cnt>=n+k-1){
						cout<<ans<<'\n';
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
