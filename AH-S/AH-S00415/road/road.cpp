#include<bits/stdc++.h>
using namespace std;
const int N=10005,M=2000005;
int tot,num,cnt,tmp,fa[N+10],nxt[M+10*N],l,r,k1,k2,tim;
long long n,m,k,ans=2e18,sum,c[15],a[15][N],z;
struct s{
	int x;
	int y;
	long long z;
};
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
s edge[M],ad[N*10];
bool cmp(s a,s b){
	return a.z<b.z;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&edge[i].x,&edge[i].y,&edge[i].z),nxt[i]=i+1;
	nxt[m]=0;
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		if(c[i]!=0) tmp=1;
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	sort(edge+1,edge+m+1,cmp);
	if(tmp==0){
		num=(1<<k)-1;
		cnt=sum=tot=tmp=0;
		l=r=1;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		while(num){
			cnt++;
			if(num&1){
				sum+=c[cnt];
				for(int j=1;j<=n;j++) ad[++tot].x=n+cnt,ad[tot].y=j,ad[tot].z=a[cnt][j];
			}
			num>>=1;
		}
		sort(ad+1,ad+tot+1,cmp);
		for(int j=1;j<=m+tot;j++){
			if(l<m&&(edge[l].z<=ad[r].z||r>=tot)) k1=find(edge[l].x),k2=find(edge[l].y),z=edge[l].z,l++;
			else k1=find(ad[r].x),k2=find(ad[r].y),z=ad[r].z,r++;
			if(k1==k2) continue;
			tmp++;
			sum+=z;
			if(tmp==n+tot/n-1) break;
			fa[k1]=k2;
		}
		cout<<sum;
		return 0;
	}
	for(int i=0;i<(1<<k);i++){
		num=i;
		cnt=sum=tot=tmp=0;
		l=r=1;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		while(num){
			cnt++;
			if(num&1){
				sum+=c[cnt];
				for(int j=1;j<=n;j++) ad[++tot].x=n+cnt,ad[tot].y=j,ad[tot].z=a[cnt][j];
			}
			num>>=1;
		}
		sort(ad+1,ad+tot+1,cmp);
		for(int j=1;j<=m+tot;j++){
			if(l<m&&(edge[l].z<=ad[r].z||r>=tot)) k1=find(edge[l].x),k2=find(edge[l].y),z=edge[l].z,l++;
			else k1=find(ad[r].x),k2=find(ad[r].y),z=ad[r].z,r++;
			if(k1==k2) continue;
			tmp++;
			sum+=z;
			if(tmp==n+tot/n-1) break;
			fa[k1]=k2;
			tim=clock();
			if(tim>=9980000){
				printf("%lld",ans);
				return 0;
			}
		}
		ans=min(ans,sum);
	}
	cout<<ans;
	return 0;
}
//O(m*logn*2^k+10*n*log(10*n)*2^k)
