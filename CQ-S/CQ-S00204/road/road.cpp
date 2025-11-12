#include<bits/stdc++.h>
using namespace std;
const long long N=1e4+15;
const long long M=1e6+5;
long long n,m,k;
long long fa[N];
struct node{
	long long l,r,v,id;
}b[M];
bool cmp(node fx,node fy){
	return fx.v<fy.v;
}
long long c[N];
long long getfa(long long x){
	if(x==fa[x]){
		return x;
	}
	fa[x]=getfa(fa[x]);
	return fa[x];
} 
node a[12][N];
long long w[N];
long long p[N],q=0;
long long t[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n;i++){
		fa[i]=i;
	}
	for(long long i=1;i<=m;i++){
		scanf("%lld%lld%lld",&b[i].l,&b[i].r,&b[i].v);
		b[i].id=i;
	}
	sort(b+1,b+1+m,cmp);
	long long cnt=0;
	for(long long i=1;i<=m;i++){
		long long fx=getfa(b[i].l);
		long long fy=getfa(b[i].r);
		if(fx!=fy){
			c[++cnt]=i;
			fa[fx]=fy;
//			cout<<b[i].l<<"->"<<b[i].r<<" "<<b[i].v<<endl;
		}
	}
	for(long long i=1;i<=k;i++){
		scanf("%lld",&w[i]);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[i][j].v);
			a[i][j].id=j;
		}
		sort(a[i]+1,a[i]+1+n,cmp);
	}
	long long ans=1e18,maxx=(1<<k)-1;
	for(long long s=0;s<=maxx;s++){
		long long cnt2=0,z=1,sum=0;
		q=0;
//		cout<<s<<":";
		for(long long i=1;i<=k;i++){
			if((s>>(i-1))&1){
				p[++q]=i;
				t[q]=1;
				sum+=w[i];
//				cout<<i<<" ";
			}
		}
//		cout<<endl;
		for(long long i=1;i<=n+k;i++){
			fa[i]=i;
		}
		while(cnt2<n-1+q){
			long long u=0;
			while(true){
				u=0;
				for(long long j=1;j<=q;j++){
					if(t[j]==n+1){
						continue;
					}
					if(a[p[j]][t[j]].v<a[p[u]][t[u]].v||u==0){
						u=j;
					}
				}
				long long fx=getfa(p[u]+n),fy=getfa(a[p[u]][t[u]].id);
				if(fx==fy&&u!=0){
					t[u]++;
				}
				else{
					break;
				}
			}
			while(z<n){
				if(getfa(b[c[z]].l)==getfa(b[c[z]].r)){
					z++;
				}
				else{
					break;
				}
			}
//			cout<<p[u]+n<<"->"<<a[p[u]][t[u]].id<<" "<<a[p[u]][t[u]].v<<endl;
			if(u!=0&&(a[p[u]][t[u]].v<b[c[z]].v||z==n)){
				sum+=a[p[u]][t[u]].v;
				long long fx=getfa(p[u]+n),fy=getfa(a[p[u]][t[u]].id);
				fa[fx]=fy;
				t[u]++;
//				cout<<"+"<<p[u]+n<<" "<<a[p[u]][t[u]].id<<" "<<a[p[u]][t[u]].v<<endl;
			}
			else{
				sum+=b[c[z]].v; 
				long long fx=getfa(b[c[z]].l),fy=getfa(b[c[z]].r);
				fa[fx]=fy;
//				cout<<" + "<<b[c[z]].l<<" "<<b[c[z]].r<<" "<<b[c[z]].v<<endl;
			}
			cnt2++;
		}
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
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
