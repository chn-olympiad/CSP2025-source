#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=1e6+5;
int n,m,k,cnt,c[MAXN],ans;
int vd[20][MAXN],f[MAXN];
int wd[1005][1005];
bool flag=1;
struct line{
	int to,fr,dis;
}a[5*MAXN];
void add(int u,int v,int w){
	a[++cnt].to=v;
	a[cnt].fr=u;
	a[cnt].dis=w;
}
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool cmp(line x,line y){
	return x.dis<y.dis;
}
int smalltree(){
	int c=0,answer=0;
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=cnt;i++){
		int u=a[i].fr,v=a[i].to;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		f[fu]=fv;
		answer+=a[i].dis;
		c++;
		if(c==n-1){
			return answer;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) flag=0;
		for(int j=1;j<=n;j++){
			scanf("%lld",&vd[i][j]);
		}
	}
	if(flag&&n<=1000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				wd[i][j]=1e9+5;
			}
		}
		for(int x=1;x<=k;x++){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					wd[i][j]=min(wd[i][j],vd[x][i]+vd[x][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				add(i,j,wd[i][j]);
			}
		}
		sort(a+1,a+1+cnt,cmp);
		ans=smalltree();
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+1+cnt,cmp);
	ans=smalltree();
	if(k==0){
		cout<<ans<<endl;
		return 0;	
	}
	for(int i=1;i<(1<<k);i++){
		int x=i,ct=0,nowcnt=0,answer=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				wd[i][j]=1e9+5;
			}
		}
		while(x!=0){
			ct++;
			if(x%2==1){
				answer+=c[ct];
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						wd[i][j]=min(wd[i][j],vd[ct][i]+vd[ct][j]);
					}
				}
			}
			x/=2;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				add(i,j,wd[i][j]);
				nowcnt++;
			}
		}
		sort(a+1,a+1+cnt,cmp);
		ans=min(ans,answer+smalltree());
		cnt-=nowcnt;
	}
	cout<<ans<<endl;
	return 0;
}
