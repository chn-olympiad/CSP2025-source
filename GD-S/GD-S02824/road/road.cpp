//T2-target 16+pts
#include<bits/stdc++.h>
#define int long long
#define N 10005
#define M 1000005
using namespace std;
int n,m,k,a,b,ans0,ans,c[15],e[15][N];
int ch[N],cnt;//mst_choose_edge 
int f[N];
int sum;
vector<int> v;//选择的乡镇 
struct aa{
	int x,y,z;
}d[M];
bool cmp(aa a, aa b){
	return a.z<b.z;
}
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	system("fc road2.ans road.out");
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i = 1; i <= n; i++ ) f[i]=i;
	for(int i = 1; i <= m; i++ ){
		scanf("%lld%lld%lld",&d[i].x,&d[i].y,&d[i].z);
	}
	for(int i = 0; i < k; i++ ){
		scanf("%lld",&c[i]);
		for(int j = 1; j <= n; j++ ){
			scanf("%lld",&e[i][j]);
		}
	}
	sort(d+1,d+1+m,cmp);
	for(int i = 1; i <= m; i++ ){
		a=find(d[i].x), b=find(d[i].y);
		if(a!=b){
			ans0+=d[i].z;
			ch[++cnt]=i;
			f[a]=b;
		}
	}
	if(k==0){//16pts
		printf("%lld",ans0);
		return 0;
	}
	ans=ans0;
	for(int i = 0; i < (1<<k); i++ ){//枚举所有乡镇的选择与否 
		v.clear();
		sum=ans0;
		for(int j = 0; j < k; j++ ){
			if(i&(1<<j)){//选择了乡镇j 
				v.push_back(j);
				sum+=c[j];
			}
		}
		for(int j = 1; j < n; j++ ){//mst所选的边 
			for(auto y:v){
				if(d[ch[j]].z>e[y][d[ch[j]].x]+e[y][d[ch[j]].y]){
					sum=sum-d[ch[j]].z+e[y][d[ch[j]].x]+e[y][d[ch[j]].y];
				}
			}
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
