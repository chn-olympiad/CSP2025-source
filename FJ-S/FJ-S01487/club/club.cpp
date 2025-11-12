#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,ans,v[4],u,flag;
struct node{
	int d[4],dmax,dmin,dmid,dd;
}a[N];
bool cnt(const node&x,const node&y){
	return x.d[x.dmax]>y.d[y.dmax];
}
void work(){
	ans=0,flag=1;
	memset(v,0,sizeof(v));
	scanf("%d",&n);
	u=n/2;
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&a[i].d[1],&a[i].d[2],&a[i].d[3]);
		int x=a[i].d[1],y=a[i].d[2],z=a[i].d[3],k;
		if(x<y){
			if(x<z){
				a[i].dmin=1;
				if(y<z)
					a[i].dmax=3,a[i].dmid=2;
				else
					a[i].dmax=2,a[i].dmid=3;
			}
			else
				a[i].dmin=3,a[i].dmax=2,a[i].dmid=1;
		}
		else{
			if(y<z){
				a[i].dmin=2;
				if(x<z)
					a[i].dmax=3,a[i].dmid=1;
				else
					a[i].dmax=1,a[i].dmid=3;
			}
			else
				a[i].dmin=3,a[i].dmax=1,a[i].dmid=2;
		}
		k=a[i].d[a[i].dmid];
		a[i].dd=a[i].d[a[i].dmin]-a[i].d[a[i].dmax];
		ans+=k,a[i].d[1]-=k,a[i].d[2]-=k,a[i].d[3]-=k;
	}
	int anss=ans;
	sort(a+1,a+n+1,cnt);
	for(int i=1;i<=n;i++){
		if(v[a[i].dmax]<u)
			v[a[i].dmax]++,ans+=a[i].d[a[i].dmax];
		else if(v[a[i].dmid]<u)
			v[a[i].dmid]++;
		else flag=0;
	}
	if(flag){
		printf("%d\n",ans);
		return ;
	}
	int e,ddmax=0xcfcfcfcf;
	for(int i=1;i<=n;i++)
		if(a[i].dd>ddmax)
			e=i,ddmax=a[i].dd;
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++){
		if(i==e)
			anss+=a[i].d[a[i].dmin];
		else if(v[a[i].dmax]<u)
			v[a[i].dmax]++,anss+=a[i].d[a[i].dmax];
		else if(v[a[i].dmid]<u)
			v[a[i].dmid]++;
	}
	printf("%d\n",anss);
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--)
		work();
	return 0;
}
