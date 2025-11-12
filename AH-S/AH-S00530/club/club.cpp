#include<bits/stdc++.h>
using namespace std;
int shu1,shu2,shu3,a[100001],b[100001],c[100001],maxc,res,n,t,e,f,g;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		shu1=0;
		shu2=0;
		shu3=0;
		maxc=0;
		res=0;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]&&a[j]>=c[j]){
				b[j]-=a[j];
				c[j]-=a[j];
				shu1++;
				maxc+=a[j];
				if(a[j]==b[j]||a[j]==c[j])res++;
			}
			if(b[j]>=a[j]&&b[j]>=c[j]){
				a[j]-=b[j];
				c[j]-=b[j];
				shu2++;
				maxc+=b[j];
				if(b[j]==c[j]||b[j]==a[j])res++;
			}
			if(c[j]>=b[j]&&c[j]>=a[j]){
				b[j]-=c[j];
				a[j]-=c[j];
				shu3++;
				maxc+=c[j];
				if(c[j]==b[j]||c[j]==a[j])res++;
			}
		}
		if(shu1<=n/2&&shu2<=n/2&&shu3<=n/2)cout<<maxc<<endl;
		else{
			if(res>=shu1-n/2&&shu2>=n/2&&shu3>=n/2){
				cout<<maxc<<endl;
			}
			else{
				if(shu1>=n/2){
					for(int t=0;t<n;t++){
						if(c[t]<=c[t+1]){
							g=max(c[t],c[t+1]);
							c[t+1]=min(c[t],c[t+1]);
							c[t]=g;
						}
					}
					for(int t=0;t<n;t++){
						if(b[t]<=b[t+1]){
							g=max(b[t],b[t+1]);
							b[t+1]=min(b[t],b[t+1]);
							b[t]=g;
						}
					}
					for(int j;;j++){
						if(b[e]>0)e++;
						else{
							if(c[f]>0)e++;
							else break;
						}
					}
					for(int j=0;j<shu1-n/2;j++){
						if(b[e]>=c[f]){
							maxc+=b[e];
							e++;
						}else{
							maxc+=c[f];
							f++;
						}
					}
					e=0;
					f=0;
					cout<<maxc<<endl;
				}
				if(shu2>=n/2){
					for(int t=0;t<n;t++){
						if(c[t]<=c[t+1]){
							g=max(c[t],c[t+1]);
							c[t+1]=min(c[t],c[t+1]);
							c[t]=g;
						}
					}
					for(int t=0;t<n;t++){
						if(a[t]<=a[t+1]){
							g=max(a[t],a[t+1]);
							a[t+1]=min(a[t],a[t+1]);
							a[t]=g;
						}
					}
					for(int j;;j++){
						if(a[e]>0)e++;
						else{
							if(c[f]>0)e++;
							else break;
						}
					}
					for(int j=0;j<shu2-n/2;j++){
						if(a[e]>=c[f]){
							maxc+=a[e];
							e++;
						}else{
							maxc+=c[f];
							f++;
						}
					}
					e=0;
					f=0;
					cout<<maxc<<endl;
				}
				if(shu3>=n/2){
					for(int t=0;t<n;t++){
						if(a[t]<=a[t+1]){
							g=max(a[t],a[t+1]);
							a[t+1]=min(a[t],a[t+1]);
							a[t]=g;
						}
					}
					for(int t=0;t<n;t++){
						if(b[t]<=b[t+1]){
							g=max(b[t],b[t+1]);
							b[t+1]=min(b[t],b[t+1]);
							b[t]=g;
						}
					}
					for(int j;;j++){
						if(a[e]>0)e++;
						else{
							if(b[f]>0)e++;
							else break;
						}
					}
					for(int j=0;j<shu3-n/2;j++){
						if(a[e]>=b[f]){
							maxc+=a[e];
							e++;
						}else{
							maxc+=b[f];
							f++;
						}
					}
					e=0;
					f=0;
					cout<<maxc<<endl;
				}
			}
		}
	}
	return 0;
}
