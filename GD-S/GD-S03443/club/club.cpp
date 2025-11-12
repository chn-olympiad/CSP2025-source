#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10,M=N<<1,inf=0x3f3f3f3f;

inline int read(){
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48; c=getchar();}
	return x*f;
}
int cnt[4],val[N][4],mx[N],cmx[N],st[N];
struct Node{
	int id,d;
	friend bool operator<(Node x,Node y){
		return x.d<y.d;
	}
};
priority_queue<Node> q;
void solve(){
	int n=read(),ans=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		mx[i]=cmx[i]=0;
		for(int j=1;j<=3;j++)
			val[i][j]=read();
		if(val[i][1]>=val[i][2]&&val[i][1]>=val[i][3]){
			mx[i]=1;
			if(val[i][2]>=val[i][3]) cmx[i]=2;
			else cmx[i]=3;
		}
		if(val[i][2]>=val[i][1]&&val[i][2]>=val[i][3]){
			mx[i]=2;
			if(val[i][1]>=val[i][3]) cmx[i]=1;
			else cmx[i]=3;
		}
		if(val[i][3]>=val[i][2]&&val[i][3]>=val[i][1]){
			mx[i]=3;
			if(val[i][1]>=val[i][2]) cmx[i]=1;
			else cmx[i]=2;
		}
		cnt[mx[i]]++;
	}
	int op=0;
	if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3]) op=1;
	else if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3]) op=2;
	else op=3;
	if(cnt[op]<=(n>>1)) for(int i=1;i<=n;i++) ans+=val[i][mx[i]];
	else{
		for(int i=1;i<=n;i++)
			if(mx[i]==op) q.push({i,val[i][mx[i]]-val[i][cmx[i]]});
			else ans+=val[i][mx[i]],st[i]=1;
		int tmp=0;
		while((++tmp)<=(n>>1)){
			Node p=q.top(); q.pop();
			st[p.id]=1,ans+=val[p.id][mx[p.id]];
		}
		while(q.size()) q.pop(); 
		for(int i=1;i<=n;i++){
			if(!st[i]) ans+=val[i][cmx[i]]; 
			st[i]=0;
		}
	}
	
	printf("%d\n",ans);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--) solve();
	return 0;
}

