#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)
typedef long long ll;

struct dat{
	int u,v,w;
};

namespace FastIO{
	const int size = 1<<20;
	char rbuf[size],*p1=rbuf,*p2=rbuf,c;
	int f;
	char mgetchar(){
		if (p1 == p2){
			p2 = (p1=rbuf)+fread(rbuf,1,size,stdin);
		}
		return (p1 == p2 ? EOF : *p1++);
	}
	void mread(int &x){
		x = 0;
		f = 1;
		c = mgetchar();
		while (c < '0' || '9' < c){
			if (c == '-')	f = -f;
			c = mgetchar();
		}
		while ('0' <= c && c <= '9'){
			x *= 10;
			x += c-'0';
			c = mgetchar();
		}
		x *= f;
	}
}

int n,m,k;
int cnt;
int u,v,w;
vector<dat> arr;
int c[15];
int cv[15][10055];
bool vis[15],flg = 1;
ll sum;
int i,j,tos;
int pre[10055];
vector<dat> vec;
ll ans = LONG_LONG_MAX;

int find(int &x){
	if (pre[x])	return pre[x] = find(pre[x]);
	return x;
}

bool cmp(dat &A,dat &B){return A.w < B.w;}

void mian(){
	memset(pre,0,sizeof(pre));
	vec.clear();
	cnt = n;
	sum = 0;
	for(i=1;i<=n;i++){
		if (vis[i]){
			sum += c[i];
			cnt++;
			for(j=1;j<=n;j++){
				vec.push_back((dat){cnt,j,cv[i][j]});
			}
		}
	}
	tos = vec.size();
	sort(vec.begin(),vec.end(),cmp);
	i = j = 0;
	while (i < m || j < tos){
		if (j >= tos || (i < m && arr[i].w < vec[j].w)){
			if (find(arr[i].u) != find(arr[i].v)){
				pre[find(arr[i].u)] = find(arr[i].v);
				sum += arr[i].w; 
			}
			i++;
		}else{
			if (find(vec[j].u) != find(vec[j].v)){
				pre[find(vec[j].u)] = find(vec[j].v);
				sum += vec[j].w; 
			}
			j++;
		}
		if (sum > ans){
			return;
		}
	}
	ans = min(ans,sum);
}

void dfs(int ind){
	if (ind > k){
		mian();
		return;
	}
	vis[ind] = 0;
	dfs(ind+1);
	vis[ind] = 1;
	dfs(ind+1);
}

int main(){
	in("road.in");
	out("road.out");
//	scanf("%d%d%d",&n,&m,&k);
	FastIO::mread(n);
	FastIO::mread(m);
	FastIO::mread(k);
	for(i=1;i<=m;i++){
//		scanf("%d%d%d",&u,&v,&w);
		FastIO::mread(u);
		FastIO::mread(v);
		FastIO::mread(w);
		arr.push_back((dat){u,v,w});
	}
	sort(arr.begin(),arr.end(),cmp);
	for(i=1;i<=k;i++){
//		scanf("%d",&c[i]);
		FastIO::mread(c[i]);
		if (c[i])	flg = 0;
		for(j=1;j<=n;j++){
//			scanf("%d",&cv[i][j]);
			FastIO::mread(cv[i][j]);
		}
	}
	if (flg){	//ÌØÊâÐÔÖÊA 
		
	}
	dfs(1);
	printf("%lld",ans);
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
