#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,b[600005],d[600005],s;
struct nood{
	int f,x,i;
};
nood a[600005];
bool cmp(nood a,nood b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);s=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&x,&y,&z);d[i]=0;
			a[i].x=x;a[i+n].x=y;a[i+2*n].x=z;
			a[i].i=i;a[i+n].i=i;a[i+2*n].i=i;
			a[i].f=1;a[i+n].f=2;a[i+2*n].f=3;
		}
		sort(a+1,a+1+3*n,cmp);x=0;y=0;z=0;
		for(int i=1;i<=3*n;i++)
		{
			if(d[a[i].i]==1)continue;
			if(a[i].f==1&&x==n/2)continue;
			if(a[i].f==2&&y==n/2)continue;
			if(a[i].f==3&&z==n/2)continue;
			if(a[i].f==1)x++;
			if(a[i].f==2)y++;
			if(a[i].f==3)z++;
			s+=a[i].x;d[a[i].i]=1;
		}
		printf("%lld\n",s);
	}
	return 0;
}
