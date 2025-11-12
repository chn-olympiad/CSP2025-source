#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int T,n;
int ans=0,lj,x,xb;
struct nod{
	int z;
	int bh;
}a[N][5],c[N];
int t[N];
bool cmp(nod x,nod y){
	return x.z>y.z;
}
bool cmd(nod x,nod y){
	return x.z<y.z;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(c,0,sizeof(c));
		memset(t,0,sizeof(t));
		scanf("%d",&n);
		lj=n/2;
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j].z);
				a[i][j].bh=j;
				sort(a[i]+1,a[i]+1+3,cmp);
				c[i].bh=a[i][1].bh;
				c[i].z=a[i][1].z-a[i][2].z;
			}
			ans+=a[i][1].z;
			t[a[i][1].bh]++;
		}
		sort(c+1,c+1+n,cmd);
		x=0,xb=0;
		for(int i=1;i<=3;i++){
			if(t[i]>lj){
				xb=i;
				x=t[i]-lj;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(x==0) break;
			if(c[i].bh==xb&&x){
				ans-=c[i].z;
				x--;
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j].bh=0,a[i][j].z=0;
			}
		}
	}
	return 0;
}
