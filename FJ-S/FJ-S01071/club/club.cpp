#include<stdio.h>
using namespace std;
int a[100005],b[100005],s[100005][4],c[100005],l[100005],cnt[4],ans,bg,tot,n,t;
int sorting(int lef,int rig){
	if(lef==rig)return 0;
	int mid=(lef+rig)/2;
	int poa=lef,pob=mid+1;
	sorting(lef,mid);
	sorting(mid+1,rig);
	for(int glup=lef;glup<=rig;glup++){
		if(poa>mid){
			b[glup]=a[pob];pob++;
		}else if(pob>rig){
			b[glup]=a[poa];poa++;
		}else if(a[poa]<a[pob]){
			b[glup]=a[poa];poa++;
		}else{
			b[glup]=a[pob];pob++;
		}
	}
	for(int glup=lef;glup<=rig;glup++){
		a[glup]=b[glup];
	}
	return 0;
}
int stintre(int p){
	bool ba=s[p][1]>s[p][2],bb=s[p][2]>s[p][3],bc=s[p][1]>s[p][3];
	if(ba&&bb&&bc){//123
		c[p]=1;l[p]=s[p][1]-s[p][2];cnt[1]++;
	}else if(ba&&!bb&&bc){//132
		c[p]=1;l[p]=s[p][1]-s[p][3];cnt[1]++;
	}else if(!ba&&bb&&bc){//213
		c[p]=2;l[p]=s[p][2]-s[p][1];cnt[2]++;
	}else if(!ba&&bb&&!bc){//231
		c[p]=2;l[p]=s[p][2]-s[p][3];cnt[2]++;
	}else if(ba&&!bb&&!bc){//312
		c[p]=3;l[p]=s[p][3]-s[p][1];cnt[3]++;
	}else if(!ba&&!bb&&!bc){//321
		c[p]=3;l[p]=s[p][3]-s[p][2];cnt[3]++;
	}
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int quest=1;quest<=t;quest++){
		ans=0;cnt[1]=0;cnt[2]=0;cnt[3]=0;tot=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i][1],&s[i][2],&s[i][3]);
			stintre(i);
			ans+=s[i][c[i]];
		}
		bg=0;
		if(cnt[1]>n/2){
			bg=1;
		}else if(cnt[2]>n/2){
			bg=2;
		}else if(cnt[3]>n/2){
			bg=3;
		}
		if(bg!=0){
			for(int i=1;i<=n;i++){
				if(c[i]==bg){
					tot++;
					a[tot]=l[i];
				}
			}
			sorting(1,tot);
			tot-=n/2;
			for(int i=1;i<=tot;i++){
				ans-=a[i];
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
