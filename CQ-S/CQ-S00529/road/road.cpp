#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pair;
void read(int& x){
	x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
}
void read(ll& x){
	x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=(x<<1ll)+(x<<3ll)+(c^'0');
		c=getchar();
	}
}
const int N=2e4+5,M=1e6+5;
int n,m,k,cnt,cntt,s;
struct edge{
	int x,y,len;
	edge(){
	}
	edge(int x_,int y_,int l_):x(x_),y(y_),len(l_){
	}
	void in(){
		read(x),read(y),read(len);
	}
}v[M*2],vv[M*2];
bool cmp(edge x,edge y){
	return x.len<y.len;
}
ll ans=1e18;
int root[N];
int find_root(int x){
	if(root[x]!=x) root[x]=find_root(root[x]);
	return root[x];
}
void mag(int x,int y){
	x=find_root(x),y=find_root(y);
	if(x==y) return ;
	root[x]=y;
}
void init(){
	for(int i=1;i<N;i++) root[i]=i;
}ll res=0;
void kruscal(){
	int cn=0;
	sort(v+1,v+1+cnt,cmp);
	init();
	for(int i=1;i<=cnt;i++){
		int x=v[i].x,y=v[i].y;
	//	cout<<v[i].len<<"----------\n";
		if(find_root(x)!=find_root(y)){
			mag(x,y);
			res+=v[i].len;
			cn++;
			v[cn]=v[i];
		}
		if(cn==s-1) break;
	}
//	for(int i=1;i<=cn;i++) cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].len<<endl;
	if(res<=ans){
		cnt=cn;
		ans=res;
		for(int i=1;i<=cnt;i++) vv[i]=v[i];
	}
	else{
		for(int i=1;i<=cnt;i++) v[i]=vv[i];
		s--;
	}
	
//	cout<<res<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k); 
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		v[++cnt].in();
	}
	s=n;
	kruscal();
	for(int i=1;i<=k;i++){
		read(res);
		s++;
		for(int j=1;j<=n;j++){
			int x;
			read(x);
			v[++cnt]=edge(j,s,x);
		}
		kruscal();
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
