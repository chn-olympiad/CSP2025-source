#include<algorithm> 
#include<iostream> 
#include<cstdio> 
#include<math.h> 
#include<string> 
#include<map> 
using namespace std;
const int N=3e6+10,M=2e4+10;
const int INF=0x3f3f3f3f;
int n,m,k,a[20][M],c[20];
int head[N],to[N],ne[N],w[N],id;
bool vis[N];
int cnt=0;
void add(int x,int y,int z){
	to[++id]=y;
	w[id]=z;
	ne[id]=head[x];
	head[x]=id;
}
int q[N],top=1;
void pushdown(int x){
	const int ls=x<<1,rs=x<<1|1;
	if(ls>top)return;
	if(rs>top){
		if(w[q[x]]>w[q[ls]]){
			swap(q[x],q[ls]);
			pushdown(ls);
		}
		return;
	}
	
	if(w[q[ls]]<w[q[rs]]){
		if(w[q[x]]>w[q[ls]]){
			swap(q[x],q[ls]);
			pushdown(ls);
		}
	}else{
		if(w[q[x]]>w[q[rs]]){
			swap(q[x],q[rs]);
			pushdown(rs);
		}
	}
}
void pushup(int x){
	if(x==1)return;
	const int f=x>>1;
	if(w[q[x]]<w[q[f]]){
		swap(q[x],q[f]);
		pushup(f);
	}
}
void qadd(int id){
	q[++top]=id;
	pushup(top);
}
void qpop(){
	q[1]=q[top];
	--top;
	pushdown(1);
}

void push(int id){
	q[++top]=id;
	pushdown(top);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int x,y,z,i=1;i<=m;i++){
		//cin>>x>>y>>z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	//cout<<"AAA";
	for(int i=1;i<=k;i++){
		cin>>c[i];
		//cout<<i<<'\n';
		for(int j=1;j<=n;j++){
			//cin>>a[i][j];
			scanf("%d",&a[i][j]);
		//cout<<i<<' '<<j<<"CCC\n";
			/*if(c[i]==0&&a[i][j]==0){
				add(j,n+i,0);
				add(n+i,j,0);
			}*/
			add(j,n+i,a[i][j]);
			add(n+i,j,a[i][j]);
			
		}
	}
	//cout<<"BBB";
	vis[1]=1;
	cnt++;
	for(int i=head[1];i;i=ne[i]){
		qadd(i);
	}
	long long ans0=0;
	//cout<<"AAA";
	while(top){
		int nid=q[1];
		qpop();
		int y=to[nid],z=w[nid];
		if(vis[y])continue;
		ans0+=z;
		vis[y]=1;
		if(y<n)cnt++;
		if(cnt==n)break;
		for(int i=head[y];i;i=ne[i])qadd(i);
	}
	//cout<<cnt;
	cout<<ans0;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
/*
5 7 0
1 2 1
1 4 2
2 4 3
2 5 5
5 3 1
3 5 3
4 5 4

*/
