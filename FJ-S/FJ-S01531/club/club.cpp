#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define int long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
inline void read(int& x){
	x=0;
	int f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	x*=f;
}
const int N=1e5+10;
struct node{
	int a,b,c;
	vector<int> v;
}a[N];
int get(node& x){
	x.v.clear();
	x.v.push_back(x.a);
	x.v.push_back(x.b);
	x.v.push_back(x.c);
	stable_sort(x.v.begin(),x.v.end(),greater<int>());
	if(x.v[0]==x.a)return 1;
	if(x.v[0]==x.b)return 2;
	if(x.v[0]==x.c)return 3;
}
bool cmp(const node& lhs,const node& rhs){
	return lhs.v[0]-lhs.v[1]<rhs.v[0]-rhs.v[1];
}
int typ[N];
vector<node> vec[4];
int buc[4];
void solve(){
	for(int i=0;i<4;i++)buc[i]=0,vec[i].clear();
	int n;
	read(n);
	int ans=0;
	for(int i=1;i<=n;i++){
		read(a[i].a),read(a[i].b),read(a[i].c);
		typ[i]=get(a[i]);
		buc[typ[i]]++;
		ans+=a[i].v[0];
//		printf("%lld ",max(max(a[i].a,a[i].b),a[i].c));
		vec[typ[i]].push_back(a[i]);
	}
//	puts("");
	for(int i=1;i<=3;i++){
		if(buc[i]>(n>>1)){
			int cnt=buc[i]-(n>>1);
			stable_sort(vec[i].begin(),vec[i].end(),cmp);
			for(int j=0;j<cnt;j++){
				ans-=vec[i][j].v[0]-vec[i][j].v[1];
//				printf("%lld ",vec[i][j].v[0]-vec[i][j].v[1]);
			}
			break;
		}
	}
//	puts("");
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	read(t);
	while(t--)solve();
}
/*
1
4
0 1 0
0 2 0
0 1 0
0 2 0
*/
