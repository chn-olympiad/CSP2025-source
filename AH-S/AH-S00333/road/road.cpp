#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct node{
	long long u,v,w;
}a[10101],d[10101];
long long n,m,k,c[11][10101],b[11],ans=0x3f3f3f3f3f3f3f3f;
long long fa[10101];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			scanf("%lld",&c[i][j]);
		}
	}
		int tp=0;
		if(k)tp=pow(2,k)-1;
		for(int i=0;i<=tp;i++){
			memset(b,0,sizeof(b));
			for(int j=1;j<=m;j++)d[j]=a[j];
			long long sum=0;
			int t1=i,cnt=k,len=m,cc=n;
			while(t1){
				if(t1&1){
					b[cnt]=1;
				}
				cnt--;
				t1>>=1;
			}
			for(int j=1;j<=k;j++){
				if(b[j]){
					cc++;
					sum+=c[j][0];
					for(int p=1;p<=n;p++){
						d[++len].u=n+j,d[len].v=p,d[len].w=c[j][p];
					}
				}
			}
			sort(d+1,d+1+len,cmp);
			for(int j=1;j<=n+k;j++)fa[j]=j;
			t1=0;
			for(int j=1;j<=len;j++){
				int x=find(d[j].u),y=find(d[j].v);
				if(x!=y){
					sum+=d[j].w;
					fa[x]=y;
					t1++;
					if(t1==cc-1)break;
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//RP++;
