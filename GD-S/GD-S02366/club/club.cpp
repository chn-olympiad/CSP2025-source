#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001],d1,d2,d3,ans,p[100001];
struct s{
	int x,y,z;
}k[100001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);d1=d2=d3=ans=0;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&k[i].x,&k[i].y,&k[i].z);
		for(int i=1;i<=n;i++){
			if(k[i].x>k[i].y&&k[i].x>k[i].z)a[++d1]=i,ans+=k[i].x;
			else if(k[i].y>k[i].z)b[++d2]=i,ans+=k[i].y;
			else c[++d3]=i,ans+=k[i].z;
		}
		if(max({d1,d2,d3})<=n/2){printf("%d\n",ans);continue;}
		if(d1>n/2)for(int i=1;i<=d1;i++)p[i]=k[a[i]].x-max(k[a[i]].y,k[a[i]].z);
		else if(d2>n/2)for(int i=1;i<=d2;i++)p[i]=k[b[i]].y-max(k[b[i]].x,k[b[i]].z);
		else for(int i=1;i<=d3;i++)p[i]=k[c[i]].z-max(k[c[i]].x,k[c[i]].y);
		sort(p+1,p+max({d1,d2,d3})+1);
		for(int i=1;i<=max({d1,d2,d3})-n/2;i++)ans-=p[i];
		printf("%d\n",ans);
	}
	return 0;
}
