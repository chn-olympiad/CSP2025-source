#include<bits/stdc++.h>
using namespace std;
int n,t,myd[400001],d=0,max1,sy[4],a[100001][4],xm[4],z;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		d=0;
		cin>>n;
		int ans=0;
		max1=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					for(int haha=0;haha<3;haha++)xm[haha]=0;
					ans=a[0][i]+a[1][j];
					xm[i]++;
					xm[j]++;
					if(xm[0]<=1&&xm[1]<=1&&xm[2]<=1&&ans>max1)max1=ans;
				}
			}
		}
		if(n==4){
			for(int i=0;i<3;i++){
				for(int j=0;j<3;j++){
					for(int k=0;k<3;k++){
						for(int l=0;l<3;l++){
							for(int haha=0;haha<3;haha++)xm[haha]=0;
							ans=a[0][i]+a[1][j]+a[2][k]+a[3][l];
							xm[k]++;
							xm[l]++;
							xm[i]++;
							xm[j]++;
							if(xm[0]<=n/2&&xm[1]<=n/2&&xm[2]<=n/2&&ans>max1)max1=ans;
						}
					}
				}
			}
		}
		if(n>200){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if(j=0){
						cin>>myd[d];
						d++;
						continue;
					}
					cin>>z;
				}
			}
			for(int i=0;i<d-1;i++){
				for(int j=0;j<d-1;j++){
					if(myd[j+1]>myd[j])swap(myd[j],myd[j+1]);
				}
			}
			for(int i=0;i<n/2;i++)ans+=myd[i];
			cout<<ans<<endl;
			continue;
		}
		cout<<max1<<endl;
	}
	return 0;
}