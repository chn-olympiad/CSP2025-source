#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
struct myd{
	int x,y,z;
};
struct sz{
	int zhi,xb;
};
bool cmp(sz a,sz b){
	if(a.zhi>b.zhi){
		return a.zhi<b.zhi;
	}else{
		return a.zhi>b.zhi;
	}
}
int myz[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	myd a[100005];
	cin>>t;
	while(t--){
		cin>>n;
		int suma=0,sumb=0,sumc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].x){
				myz[i]=1;
				suma++;
			}
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].y){
				myz[i]=2;
				sumb++;
			}
			if(max(a[i].x,max(a[i].y,a[i].z))==a[i].z){
				myz[i]=3;
				sumc++;
			}
		}
		if(suma<=n/2&&sumb<=n/2&&sumc<=n/2){
			for(int i=1;i<=n;i++){
				if(myz[i]==1){
					ans+=a[i].x;
				}else if(myz[i]==2){
					ans+=a[i].y;
				}else if(myz[i]==3){
					ans+=a[i].z;
				}
			}
			cout<<ans<<endl;
			suma=0,sumb=0,sumc=0;
			ans=0;
			continue;
		}else if(suma>n/2){
			sz da[100005];
			int lena=0;
			for(int i=1;i<=n;i++){
				if(myz[i]==1){
					da[lena].zhi=a[i].x;
					da[lena].xb=i;
					lena++;
				}else if(myz[i]==2){
					ans+=a[i].y;
				}else if(myz[i]==3){
					ans+=a[i].z;
				}
			}
			sort(da,da+lena,cmp);
			for(int i=lena-1;i>=0;i--){
				if(i+2-(n/2)>=n/2&&lena!=2){
					ans+=da[i].zhi;
				}else{
					if(a[da[i].xb].y>a[da[i].xb].z){
						ans+=a[da[i].xb].y;
					}else{
						ans+=a[da[i].xb].z;
					}
					
				}
			}
			cout<<ans;
			suma=0,sumb=0,sumc=0;
			ans=0;
			continue;
		}
		else if(sumb>n/2){
			sz db[100005];
			int lenb=0;
			for(int i=1;i<=n;i++){
				if(myz[i]==2){
					db[lenb].zhi=a[i].y;
					db[lenb].xb=i;
					lenb++;
				}else if(myz[i]==1){
					ans+=a[i].x;
				}else if(myz[i]==3){
					ans+=a[i].z;
				}
			}
			sort(db,db+lenb,cmp);
			for(int i=lenb-1;i>=0;i--){
				if(i+2-(n/2)>=n/2&&lenb!=2){
					ans+=db[i].zhi;
				}else{
					if(a[db[i].xb].x>a[db[i].xb].z){
						ans+=a[db[i].xb].x;
					}else{
						ans+=a[db[i].xb].z;
					}
					
				}
			}
			cout<<ans;
			suma=0,sumb=0,sumc=0;
			ans=0;
			continue;
		}
		else if(sumc>n/2){
			sz dc[100005];
			int lenc=0;
			for(int i=1;i<=n;i++){
				if(myz[i]==3){
					dc[lenc].zhi=a[i].z;
					dc[lenc].xb=i;
					lenc++;
				}else if(myz[i]==1){
					ans+=a[i].x;
				}else if(myz[i]==2){
					ans+=a[i].y;
				}
			}
			sort(dc,dc+lenc,cmp);
			for(int i=lenc-1;i>=0;i--){
				if(i+2-(n/2)>=n/2&&lenc!=2){
					ans+=dc[i].zhi;
				}else{
					if(a[dc[i].xb].x>a[dc[i].xb].y){
						ans+=a[dc[i].xb].x;
					}else{
						ans+=a[dc[i].xb].y;
					}
					
				}
			}
			cout<<ans;
			suma=0,sumb=0,sumc=0;
			ans=0;
			continue;
		}
		
		
		
		
	}
	
	
	
	
	return 0;
}
