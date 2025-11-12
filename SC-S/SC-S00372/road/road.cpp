#include<bits/stdc++.h>
using namespace std;
int const N=1e4+1;
struct edge{//a<b
	int st,ed,val;
};
vector<edge> vec;
int C[N],fa[N],cnt[N];
long long ans=0;
int n,m,k,a,b,c;
bool operator < (edge i,edge j){
	return i.val<j.val;
}
long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<1)+(res<<3)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		print(x/10);
	}
	putchar((x%10)^48);
}
void prep(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		cnt[i]=1;
	}
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa[x]);
}
void unite(int x,int y){
	cnt[fa[y]]+=cnt[find(x)];
	fa[find(x)]=find(y);
}
void kruskal(){
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++){
		a=vec[i].st;
		b=vec[i].ed;
		c=vec[i].val;
		if(find(a)==find(b)){
			continue;
		}
		if(b>n&&fa[b]==b){
			ans+=C[i];
		}
		unite(a,b);
		ans+=c;
//		cout<<a<<' '<<b<<' '<<cnt[fa[a]]<<'\n';
		if(cnt[fa[a]]==n){
			break;
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	prep();
	for(int i=0;i<m;i++){
		a=read();
		b=read();
		c=read();
		if(a>b){
			swap(a,b);
		}
		vec.push_back({a,b,c});
	}
	for(int i=1;i<=k;i++){
		C[i]=read();
		for(int j=1;j<=n;j++){
			a=read();
			vec.push_back({j,n+i,a});
		}
	}
	kruskal();
	print(ans);
	return 0;
}