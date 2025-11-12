#include<bits/stdc++.h>
using namespace std;
int t,n,sum;
bool a11=true,b=true,c=true;
struct pp{
	int aa,bb,cc;
	int id;
	int ma(){
		return max(aa,max(bb,cc));
	}
}a[10005];
bool cmp(pp pl,pp lp){
	return pl.ma()>lp.ma();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].aa,&a[i].bb,&a[i].cc);
			if(a[i].cc!=0) a11=false,b=false;
			if(a[i].bb!=0) a11=false;
		}
		if(a11){
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n/2;i++) sum+=a[i].aa;
			printf("%d\n",sum);
		}else{
			sort(a+1,a+n+1,cmp);
			int bm1=n/2,bm2=n/2,bm3=n/2;
			for(int i=1;i<=n;i++){
				int zd=max(a[i].aa,max(a[i].bb,a[i].cc));
				if(zd==a[i].aa){
					if(bm1!=0) sum+=a[i].aa,bm1--;
					else{
						if(a[i].bb>a[i].cc) if(bm2!=0) sum+=a[i].bb,bm2--;
						else sum+=a[i].cc,bm3--;
					}	
				}
				if(zd==a[i].bb){
					if(bm2!=0) sum+=a[i].bb,bm2--;
					else{
						if(a[i].aa>a[i].cc) if(bm1!=0) sum+=a[i].aa,bm1--;
						else sum+=a[i].cc,bm3--;
					}	
				}
				if(zd==a[i].cc){
					if(bm3!=0) sum+=a[i].cc,bm3--;
					else{
						if(a[i].aa>a[i].bb) if(bm1!=0) sum+=a[i].aa,bm1--;
						else sum+=a[i].bb,bm2--;
					}	
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}

