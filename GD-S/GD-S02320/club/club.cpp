#include<bits/stdc++.h>
const int N=1e5+22;
using namespace std;
struct node{
	int val,id;
	
	friend bool operator < (node x,node y){
		return x.val>y.val;
	}
}a[N],b[N],c[N],d[N],e[N];
int n,ma;
void dfs1(int x,int one,int ont,int two,int tnt,int the,int ent){
	if(x>n){
		ma=max(ma,one+two+the);
		return ;
	}
	if(ont<n/2) dfs1(x+1,one+a[x].val,ont+1,two,tnt,the,ent);
	if(tnt<n/2) dfs1(x+1,one,ont,two+b[x].val,tnt+1,the,ent);
	if(ent<n/2) dfs1(x+1,one,ont,two,tnt,the+c[x].val,ent+1);
}
void dfs2(int x,int one,int ont,int two,int tnt){
	if(x>n){
		cout<<one<<' '<<two<<' '<<one+two<<endl;
		ma=max(ma,one+two);
		return ;
	}
	if(ont<n/2) dfs2(x+1,one+a[x].val,ont+1,two,tnt);
	if(tnt<n/2) dfs2(x+1,one,ont,two+b[x].val,tnt+1);
}
void check(node x[],node y[],node z[]){
	for(int i=1;i<=n;i++) d[i]={x[i].val-y[i].val-z[i].val,i};
	sort(d+1,d+n+1);
	int sum=0;
	vector <bool> vis(N,0);
	for(int i=1;i<=n/2;i++) sum+=x[d[i].id].val,vis[d[i].id]=1;
	int awa=0,owo=0;
	for(int i=1;i<=n;i++) if(!vis[i]) e[i]={y[i].val-z[i].val,i};
	for(int i=n/2+1;i<=n/4;i++) awa+=y[e[i].id].val;
	for(int i=n/4+1;i<=n;i++) awa+=z[e[i].id].val;
	for(int i=1;i<=n;i++) if(!vis[i]) e[i]={z[i].val-y[i].val,i};
	for(int i=n/2+1;i<=n/4;i++) owo+=z[e[i].id].val;
	for(int i=n/4+1;i<=n;i++) owo+=y[e[i].id].val;
	ma=max(ma,sum+max(awa,owo));
}
void solve(){
	int flA=1,flB=1;
	scanf("%d",&n);
//	cout<<n<<endl;
	ma=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].val,&b[i].val,&c[i].val);
//		cout<<a[i].val<<' '<<b[i].val<<' '<<c[i].val<<endl;
		if(b[i].val) flA=0;
		if(c[i].val) flB=0;
		a[i].id=b[i].id=c[i].id=i;
	}
	if(flA){
		sort(a+1,a+n+1);
		int sum=0;
		for(int i=1;i<=n/2;i++) sum+=a[i].val;
		printf("%d\n",sum);
		return ;
	}else if(flB){
		for(int i=1;i<=n;i++) d[i]={a[i].val-b[i].val,i};
		sort(d+1,d+n+1);
		int sum=0;
		for(int i=1;i<=n/2;i++) sum+=a[d[i].id].val;
		for(int i=n/2+1;i<=n;i++) sum+=b[d[i].id].val;
		printf("%d\n",sum);
		return ;
	}
	if(n<=10){
		dfs1(1,0,0,0,0,0,0);
		printf("%d\n",ma);
	}else{
		check(a,b,c);
		check(b,a,c);
		check(c,a,b);
		printf("%d\n",ma);
	}
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
}
