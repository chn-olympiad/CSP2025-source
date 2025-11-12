#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5,maxm=1e6+5,maxm2=2e6+5,maxk=15,maxs=1030;

int fa[maxn];
int Find_fa(int x){ return fa[x]==x?x:fa[x]=Find_fa(fa[x]); }

struct LINE{ int x,y; ll z; }a[maxm],rla[maxm],nwa[maxm2];
bool cmp(LINE a,LINE b){ return a.z<b.z; }

int SS[maxs],nwctr[maxk];
struct NODE{ ll ct,w[maxn]; }ctr[maxk];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k; scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int cnt=0; ll res=0;
	for(int i=1;i<=m;i++){
		int fx=Find_fa(a[i].x),fy=Find_fa(a[i].y);
		if(fx!=fy){
			fa[fy]=fx,res+=a[i].z;
			rla[++cnt]=a[i];
			if(cnt==n-1) break;
		}
	}
	int k2=0;
	for(int i=1,x;i<=k;i++){
		scanf("%d",&x);
		if(x>res){
			for(int j=1,y;j<=n;j++)
				scanf("%d",&y);
		}
		else{
			ctr[++k2].ct=x;
			for(int j=1;j<=n;j++){
				scanf("%lld",&ctr[k2].w[j]);
			}
		}
	}
	int S=(1<<k2)-1,oks=0,tmp=0,op=0; ll sum=0;
	for(int i=1;i<=S;i++){
		sum=0;
		for(int j=1;j<=k2;j++)
			if((1<<(j-1))&i) sum+=ctr[j].ct;
		if(sum<=res) SS[++oks]=i;
	}
	for(int i=1;i<=oks;i++){
		ll sum=0; int len=0;
		for(int j=1;j<=k2;j++)
			if((1<<(j-1))&SS[i]){
				nwctr[++len]=j;
				sum+=ctr[j].ct;
			}
		tmp=0;
		for(int j=1;j<=len;j++)
			for(int p=1;p<=n;p++)
				nwa[++tmp]=(LINE){n+j,p,ctr[nwctr[j]].w[p]};
		for(int j=1;j<n;j++)
			nwa[++tmp]=rla[j];
		sort(nwa+1,nwa+tmp+1,cmp);
		for(int j=1;j<=n+len;j++)
			fa[j]=j;
		op=0;
		for(int j=1;j<=tmp;j++){
			int fx=Find_fa(nwa[j].x),fy=Find_fa(nwa[j].y);
			if(fx!=fy){
				fa[fy]=fx;
				sum+=nwa[j].z;
				op++;
				if(sum>=res) break;
				if(op==n+len-1){
					res=sum;
					break;
				}
			}
		}
	}
	printf("%lld",res);
	return 0;
}
