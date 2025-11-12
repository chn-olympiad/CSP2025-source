#include <bits/stdc++.h>
using namespace std;
long long t,n[100010],k,a[100010],b[100010],c[100010],aa,bb,cc;
long long aon[100010],bon[100010],con[100010],sum[100010],tja[100010],smln;
long long tjb[100010],tjc[100010];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		smln=n[i];
		for(int j=1;j<=smln;j++){
			cin>>a[j]>>b[j]>>c[j];
			
		}
		aa=0;
		bb=0;
		cc=0;
		for(int j=1;j<=smln;j++){
			
			if(a[j]>b[j]&&a[j]>c[j]){
				if(aa<smln/2){
					aa++;
				aon[j]=a[j];
				}
				else {
					smln=n[i];
					sort(tja+1,tja+1+smln);
					if(a[j]>=tja[1]){
						for(int k=1;k<=smln;k++){
						if(tja[1]==aon[k]){
							aon[k]=0;
							aon[k]=a[j];
							if(b[k]>=c[k]){
								bon[k]=b[k];
								bb++;
							}
							else if(b[k]<=c[k]){
								con[k]=c[k];
								cc++;
							}
							break;
						}
					}
					}
					
				}
				
			}
			else if(b[j]>a[j]&&b[j]>c[j]){
				if(bb<smln/2){
					bb++;
				bon[j]=b[j];
				}
				else {
					smln=n[i];
					sort(tjb+1,tjb+1+smln);
					if(b[j]>=tjb[1]){
						for(int k=1;k<=smln;k++){
						if(tjb[1]==bon[k]){
							bon[k]=0;
							bon[k]=b[j];
							if(a[k]>=c[k]){
								aon[k]=a[k];
								aa++;
							}
							else if(a[k]<=c[k]){
								con[k]=c[k];
								cc++;
							}
							break;
						}
					}
					}
					
				}
				
			}
			else if(c[j]>b[j]&&c[j]>a[j]){
				if(cc<smln/2){
				cc++;
				con[j]=c[j];
				}
											else {
					smln=n[i];
					sort(tjc+1,tjc+1+smln);
					if(c[j]>=tjc[1]){
						for(int k=1;k<=smln;k++){
						if(tjc[1]==con[k]){
							con[k]=0;
							con[k]=c[j];
							if(b[k]>=a[k]){
								bon[k]=b[k];
								bb++;
							}
							else if(b[k]<=a[k]){
								aon[k]=a[k];
								aa++;
							}
							break;
						}
					}
					}
					
				}
			}
			else {
				if(c[j]==b[j]&&c[j]==0){
						if(aa<smln/2){
					aa++;
				aon[j]=a[j];
				}
				}
				else 	if(c[j]==a[j]&&c[j]==0){
						if(bb<n[i]/2){
					bb++;
				bon[j]=b[j];
				}
				}
				else 	if(b[j]==a[j]&&b[j]==0){
						if(cc<n[i]/2){
					cc++;
				con[j]=c[j];
				}

				}
			}
			tja[j]=aon[j];
			tjb[j]=bon[j];
			tjc[j]=con[j];
}


	for(int j=1;j<=n[i];j++){
			
			if(aon[j]>bon[j]&&aon[j]>con[j]){
				if(aa<=n[i]/2){
					sum[i]+=aon[j];
				}
				
				
			}
			else if(bon[j]>aon[j]&&bon[j]>con[j]){
				if(bb<=n[i]/2){
					sum[i]+=bon[j];
				}
				
			}
			else if(con[j]>bon[j]&&con[j]>aon[j]){
				if(cc<=n[i]/2){
				sum[i]+=con[j];
				}
			
			}
			
}
		
	}
	for(int i=1;i<=t;i++){
		cout<<sum[i]<<endl;
	}

	return 0;
}
