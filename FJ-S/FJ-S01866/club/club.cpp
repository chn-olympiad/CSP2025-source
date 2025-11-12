#include<bits/stdc++.h>
using namespace std;
int t,n,flag,flagg,ans;
int a[100010];
int b[100010];
int c[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(b[j]!=0 || c[j]!=0){
				flag=1;
			} 
			if(c[j]!=0){
				flagg=1;
			}
		}
		if(flag==0){
			int maxx=0;
			for(int j=1;j<=n;j++){
				if(a[j]>maxx){
					maxx=a[j];
				}
			}
			ans=maxx;
		}else if(flagg==0){
			int am=0,bm=0,aa,bb;
			for(int j=1;j<=n;j++){
				if(a[j]>am){
					am=a[j];
					aa=j;
				}
				if(b[j]>bm){
					bm=b[j];
					bb=j;
				}
			}
			if(aa!=bb){
				ans=ans+am+bm;
			}else{
				int amm=0,bmm=0;
				for(int j=1;j<=n;j++){
					if(j!=aa && a[j]>amm){
						amm=a[j];
					}
					if(j!=bb && b[j]>bmm){
						bmm=b[j];
					}
				}
				ans=max(am+bmm,amm+bm);
			}
		}
		if(n==2){
			int maxx=0;
			if(max(a[1]+b[2],a[1]+c[2])>maxx){
				maxx=max(a[1]+b[2],a[1]+c[2]);
			}
			if(max(b[1]+a[2],b[1]+c[2])>maxx){
				maxx=max(b[1]+a[2],b[1]+c[2]);
			}
			if(max(c[1]+a[2],c[1]+b[2])>maxx){
				maxx=max(c[1]+a[2],c[1]+b[2]);
			}
			ans=maxx;
		}
		cout<<ans<<endl;
	}
	return 0;
} 
