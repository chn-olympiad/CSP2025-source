#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[11451451],b[11451451],c[11451451],d[11454141],e[1145141],f[1145141],bx,tot=1e9,sum,hm,bm1,bm2,bm11,bm22,ans;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=1;j<=m;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(b[j]==0) bx++;
			if(c[j]==0) bx++;
			if(bx>=2) sum++;
			bx=0;
		}
		if(sum==m){
			if(a[1]!=0){
				sort(a+1,a+1+m);
				for(int j=m;j>m/2;j--) ans+=a[j];
			}
			cout<<ans<<"\n";
			sum=0;
		}
		else{
			for(int j=1;j<=m;j++){
				d[j]=a[j];
				e[j]=b[j];
			}
			sort(d+1,d+1+m);
			sort(e+1,e+1+m);
			for(int j=m;j>m/2;j--){
				bm1+=d[j];
				bm2+=e[j];
			}
			if(bm1==bm2){
				for(int k=m;k>m/2;k--){
					for(int j=1;j<=m;j++){
						if(a[j]==d[k]){
							if(min(tot,a[j]+b[j])==a[j]+b[j]){
								tot=a[j]+b[j];
								hm=j;
							}
						}
					}
					a[hm]=0;
					b[hm]=0;
					hm=0;
					tot=1e9;
				}
				for(int j=1;j<=m;j++){
					bm11+=a[j];
					bm22+=b[j];
				}
				if(bm11>bm22) ans=bm11+bm2;
				else ans=bm22+bm1;
				cout<<ans<<"\n";
			}
			else if(max(bm1,bm2)==bm1){
				for(int k=m;k>m/2;k--){
					for(int j=1;j<=m;j++){
						if(a[j]==d[k]){
							if(min(tot,a[j]+b[j])==a[j]+b[j]){
								tot=a[j]+b[j];
								hm=j;
							}
						}
					}
					a[hm]=0;
					b[hm]=0;
					hm=0;
					tot=1e9;
				}
				ans+=bm1;
				for(int j=1;j<=m;j++) ans+=b[j];
				cout<<ans<<"\n";
			}
			else{
				for(int k=m;k>m/2;k--){
					for(int j=1;j<=m;j++){
						if(b[j]==e[k]){
							if(min(tot,a[j]+b[j])==a[j]+b[j]){
								tot=a[j]+b[j];
								hm=j;
							}
						}
					}
					a[hm]=0;
					b[hm]=0;
					hm=0;
					tot=1e9;
				}
				ans+=bm2;
				for(int j=1;j<=m;j++) ans+=a[j];
				cout<<ans<<"\n";
			}
			bm1=0;
			bm2=0;
			bm11=0;
			bm22=0;
		}
		ans=0;
	}
}
