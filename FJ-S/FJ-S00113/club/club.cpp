#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll Min(ll x,ll y){return x<y?x:y;}
inline ll Max(ll x,ll y){return x>y?x:y;}
inline void cmin(ll &x,ll y){x=Min(x,y);}
/*-----------------*/
const int N=1e5+10;
const ll inf=1e18;
int T,n,m[3],k,p,q;
ll a[N][3],sum[N];
vector<int> id[3];
inline bool cmp1(int x,int y){
	return sum[x]<sum[y];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		for(int j=0;j<=2;j++)
			scanf("%lld",&a[i][j]);
		for(int i=0;i<=2;i++)
			id[i].clear();
		for(int i=1;i<=n;i++){
			int mx=-1,f=0;
			for(int j=0;j<=2;j++){
				if(a[i][j]>mx){
					mx=a[i][j];
					f=j;
				}
			}
			id[f].push_back(i);
		}
		for(int i=0;i<=2;i++) m[i]=id[i].size();
		ll ans=0;
		for(int i=0;i<=2;i++)
		for(int j=0;j<m[i];j++)
			ans+=a[id[i][j]][i];
		if(Max(m[0],Max(m[1],m[2]))<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		k=0,p=0,q=0;
		for(int i=0;i<=2;i++) if(m[i]>n/2) k=i;
		if(k==0) p=1,q=2;
		else if(k==1) p=0,q=2;
		else if(k==2) p=0,q=1;
		for(int i=0;i<m[k];i++){
			int x=id[k][i];
			sum[x]=a[x][k]-Max(a[x][p],a[x][q]);
		}
		sort(id[k].begin(),id[k].end(),cmp1);
		int d=m[k]-n/2;
		for(int i=0;i<d;i++){
			int x=id[k][i];
			ans-=sum[x];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
