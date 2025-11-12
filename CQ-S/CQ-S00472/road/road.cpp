#define allLL
#include<bits/stdc++.h>
using namespace std;
#define N 500005
template<typename T>T Max(T x,T y){return (x<y?y:x);}
template<typename T>T Min(T x,T y){return (x<y?x:y);}
#define LL long long
#ifdef allLL
#define int LL
const int INF=(1e18);
#else
const int INF=(1e9);
#endif
template<typename T>void read(T&x){
x=0;char c=getchar();/*T fh=1;*/
while(c<'0'||'9'<c){/*if(c=='-'){fh=-1;}*/c=getchar();}
while('/'<c&&c<':'){x=x*10+(c^'0');c=getchar();}/*x*=fh;*/}
template<typename T>void write(T x){
if(x<0){putchar('-');x=-x;}if(x>9){write(x/10);}putchar('0'+(x%10));}
struct st{
	int x,y,val;
	bool operator < (const st& oth) const{
		return val<oth.val;
	}
};
vector<st> al;
int f[N];
int siz[N];
int find(int u){
	return (u==f[u]?u:f[u]=find(f[u])); 
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return ;
	if(siz[x]<siz[y])f[x]=y,siz[y]+=siz[x];
	else f[y]=x,siz[x]+=siz[y];
}
int n,m,k;
vector<st> res;
void solve1(){
	sort(al.begin(),al.end());
	for(int i=1;i<=n;i++)f[i]=i,siz[i]=1;
	for(auto p:al){
		if(find(p.x)==find(p.y))continue;
		res.push_back(p);
		merge(p.x,p.y);
//		cerr<<p.x<<','<<p.y<<endl;
	}
}
vector<st> nw;
int c[N];
#undef int
int main(){
#ifdef allLL
#define int LL
#endif
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n);
	read(m);
	read(k);
	for(int i=1,x,y,z;i<=m;i++){
		read(x),read(y),read(z);
		al.push_back({x,y,z});
	}
	solve1();
	for(int i=1;i<=k;i++){
		read(c[i]);
		for(int j=1;j<=n;j++){
			int x;
			read(x);
			nw.push_back({i+n,j,x});
		}
	}
	sort(nw.begin(),nw.end());
	int ans=INF;
	for(int b=0;b<(1<<k);b++){
//		cout<<b<<"::\n";
		int sm=0;
		for(int i=1;i<=k;i++)if((b>>(i-1))&1)sm+=c[i];
		
		for(int i=1;i<=n+k;i++)f[i]=i,siz[i]=1;
		int i1=0,i2=0;
		while(i1<=(int)res.size()-1||i2<=(int)nw.size()-1){
			st p;
			while(i2<(int)nw.size()){
				if(!((b>>(nw[i2].x-n-1))&1))i2++;
				else break;
			}
			if(i1>(int)res.size()-1)p=nw[i2++];
			else if(i2>(int)nw.size()-1)p=res[i1++];
			else{
				if(res[i1]<nw[i2])p=res[i1++];
				else p=nw[i2++];
			}
			if(find(p.x)==find(p.y))continue;
			sm+=p.val;
			merge(p.x,p.y);
		}
		ans=Min(ans,sm);
	}
	write(ans);
	cerr<<clock()<<endl;
	return 0;
#undef int
}
/*

*/
