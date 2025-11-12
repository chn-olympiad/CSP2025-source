#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
inline int read();
const int N = 5e6 + 10,M = 5e4 + 10,inf=1e16;
struct node{
	int l,r,val;
}aa[N],aa1[N],aay[N];
int fa[M];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
bool cmp(node x,node y){
	return x.val < y.val;
}
LL c[M];
int d[13][M];
LL ans=inf;
int n,m,k;
int idx;
int vv[M];
void solve(int x){
	LL plu=0;
	int X = x;
	for(int i=1;i<=k;i++){
		if((X & 1) && vv[i]) return;
		X>>=1;
	}
	
	for(int i=1;i<=k;i++){
		if(x & 1){
			for(int j=1;j<=n;j++){
				aa[++idx] = {i + n,j,d[i][j]};
			}
			plu+=c[i];
		}
		x>>=1;
	}
	for(int i=1;i<=n + k;i++){
		fa[i] = i;
	}
	sort(aa+1,aa+1+idx,cmp);
	LL ans1 = 0;
	for(int i=1;i<=idx;i++){
		int xx = find(aa[i].l);
		int yy = find(aa[i].r);
		if(xx != yy){
			ans1+=aa[i].val;
			fa[xx] = yy;
		}
	}
	ans = min(ans,ans1+plu);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		int a,b,c;
		a=read();b=read();c=read();
		//aa[i] = {a,b,c};
		aa1[i] = {a,b,c};
	}
	for(int i=1;i<=n;i++){
		fa[i] = i;
	}
	sort(aa1+1,aa1+1+m,cmp);
	LL ansy = 0;
	for(int i=1;i<=m;i++){
		int xx = find(aa1[i].l);
		int yy = find(aa1[i].r);
		if(xx != yy){
			fa[xx] = yy;
			aa[++idx]=aa1[i];
			
			ansy+=aa1[i].val;
		}
	}
	//cout<<ansy<<" ";
	//cout<<idx<<" "<<n-1<<endl;
	idx=n-1;
	for(int i=1;i<=idx;i++) aay[i] = aa[i];
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++){
			d[i][j] = read();
		}
	}
	for(int i=1;i<=k;i++){
		idx=n-1;
		for(int j=1;j<=idx;j++){
			aa[j]=aay[j];
		}
		for(int j=1;j<=n;j++){
			aa[++idx] = {i + n,j,d[i][j]};
		}
		for(int kk=1;kk<=n + k;kk++){
			fa[kk] = kk;
		}
		sort(aa+1,aa+1+idx,cmp);
		LL ans2 = 0;
		for(int kk=1;kk<=idx;kk++){
			int xx = find(aa[kk].l);
			int yy = find(aa[kk].r);
			if(xx != yy){
				ans2+=aa[kk].val;
				fa[xx] = yy;
			}
		}
		if(ans2+c[i] >= ansy){
			vv[i] = 1;
			//cout<<i<<endl;
		}
	}
	int upp=1;
	for(int i=1;i<k;i++){
		upp*=2;
	}
	for(int i=0;i<upp;i++){
		idx = n-1;
		for(int j=1;j<=idx;j++) aa[j] = aay[j]; 
		solve(i);
	}
	cout<<min(ans,ansy);

}
inline int read(){
	char x=getchar();
	int res = 0;
	int f = 1;
	while(x < '0' || x >'9'){
		if(x == '-') f =-1;
		x = getchar();
	}
	while(x >='0' && x <='9'){
		res = res * 10 + (x -'0');
		x=getchar();
	}
	return res * f;
}

