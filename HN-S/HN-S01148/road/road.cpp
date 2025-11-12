#include<bits/stdc++.h>//60
#define int long long
using namespace std;
void read(int &x){
	x=0;
	int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
void read(string &str){
	str="";
	char ch=getchar();
	while(ch<'!'||ch>'~')ch=getchar();
	while(ch>='!'&&ch<='~')str+=ch,ch=getchar();
}
void write(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}
void write(string str){
	for(int i=0;i<str.size();i++)putchar(str[i]);
}
void write(const char ch[]){
	for(int i=0;i<strlen(ch);i++)putchar(ch[i]);
}
template<typename o,typename...c>
void read(o &a,c&...b){
	read(a);
	read(b...);
}
template<typename o,typename...c>
void write(o a,c...b){
	write(a);
	write(b...);
}
int n,m,k,i,j,q,z,w,a[20][10101],Min=INT_MAX;bool v[20];
struct edge{
	int q,z,w;
};
vector<edge>Edge;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int bcj[10101],js;
void csh(int n){
	for(int i=1;i<=n;i++)bcj[i]=i;
	js=n;
}
int Find(int x){
	if(bcj[x]==x)return x;
	return bcj[x]=Find(bcj[x]);
}
bool Same(int a,int b){
	int fa=Find(a),fb=Find(b);
	return fa==fb;
}
void Union(int a,int b){
	int fa=Find(a),fb=Find(b);
	if(fa!=fb)bcj[fa]=fb,js--;
}
int mt(int n,int sum){
	csh(n);
	vector<edge>EDGE;
	for(int i=0;i<Edge.size();i++)EDGE.push_back((edge){Edge[i].q,Edge[i].z,Edge[i].w});
	sort(EDGE.begin(),EDGE.end(),cmp);
	for(int i=0;i<EDGE.size();i++){
		int q=EDGE[i].q,z=EDGE[i].z,w=EDGE[i].w;
		if(Same(q,z))continue;
		Union(q,z);
		sum+=w;
		if(js==1)return sum;
	}
	return INT_MAX;
}
void dfs(int sum,int C){
	Min=min(Min,mt(n+C-1,sum));
	if(C>k)return;
	for(int i=1;i<=k;i++){
		if(!v[i]){
			for(int j=1;j<=n;j++)Edge.push_back((edge){i+n,j,a[i][j]});
			dfs(sum+a[i][0],C+1);
			for(int j=1;j<=n;j++)Edge.pop_back();
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n,m,k);
	for(i=1;i<=m;i++){
		read(q,z,w);
		Edge.push_back((edge){q,z,w});
	}
	for(i=1;i<=k;i++){
		for(j=0;j<=n;j++)read(a[i][j]);
	}
	dfs(0,1);
	write(Min);
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


6 6 0
1 4 3
4 6 7
3 5 2
5 6 2
2 3 1
2 6 6

15
*/
