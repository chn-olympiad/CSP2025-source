#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar(); 
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
struct tree{
	int la,to,w;
};
bool cmp(tree a,tree b){
	return a.w<b.w;
}
vector<tree> mp;
int fa[10010];
int findx(int x){
	if(x==fa[x]){
		return fa[x];
	}
	findx(fa[x]);
}
void merge(int x,int y){
	x=findx(x),y=findx(y);
	if(fa[x]!=y) fa[x]=y;
}
int kruskal(){
	int ans=0,tim=0;
	for(auto a:mp){
		if(findx(a.la)!=findx(a.to)){
			merge(a.la,a.to);
			//cout<<
			tim++;
			ans+=a.w;
		}
		if(tim==n-1) return ans;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		fa[i]=i;
		tree a;
		a.la=read();
		a.to=read();
		a.w=read();
		mp.push_back(a);
		tree b;
		b.la=a.to;
		b.to=a.la;
		b.w=a.w;
		mp.push_back(b);
	}
	sort(mp.begin(),mp.end(),cmp);
	cout<<kruskal();
	return 0;
}
