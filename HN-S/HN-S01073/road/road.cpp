#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10010
#define oo INT_MAX
int n,m,k,c[N],fa[N],ans=oo,cnt=1;
struct node{
	int u,v,w;
};
vector<node> edge[N];
vector<int>cit[N];
vector<node>st;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}return x*f;
}
void write(int x){
	static int st[40],top=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	while(x){
		st[++top]=x%10;
		x/=10;
	}if(top==0) st[++top]=0;
	while(top) putchar(st[top--]);
	return ;
}
bool usedk[N];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void solve(int nowcost,int p){
	if(cnt==n) {
		ans=min(ans,nowcost);
		return ;
	}
	for(int i=p+1;i<st.size();i++){
		int un=st[i].u,vn=st[i].v;
		int fu=find(un),fv=find(vn);
		if(fu==fv) continue;
		fa[fu]=fv;
		if(vn>n&&usedk[vn-n]!=0) {
			usedk[vn-n]=1;
			solve(nowcost+st[i].w+c[vn-n],i);
			usedk[vn-n]=0;
		}
		else solve(nowcost+st[i].w,i);
	}return ;
}
bool cmp(node x,node y){
	return x.w <y.w ;
}
signed main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		edge[u].push_back((node){u,v,w});
		edge[v].push_back((node){u,v,w});
		st.push_back((node){u,v,w});
	}
	for(int i=1;i<=k+n;i++) fa[i]=i; 
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) {
			int t=read();
			cit[i].push_back(t);
			st.push_back((node){i,k+n,t});
		}
	}
	sort(st.begin(),st.end(),cmp);
	solve(0,0);
	cout<<ans;
	return 0; 
}
