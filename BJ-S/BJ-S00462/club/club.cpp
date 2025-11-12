#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int a[n],b[n],c[n];
		int asum=0,bsum=0,csum=0;
		long long ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				asum++;
				ans+=a[i];
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				bsum++;
				ans+=b[i];
			}else{
				csum++;
				ans+=c[i];
			}
		}
		if(asum<=n/2&&bsum<=n/2&&csum<=n/2){
			cout<<ans<<endl;
			continue;
		}
		int j[n];
		int zdz=0;
		if(asum>n/2){
			zdz=asum;
			for(int i=0;i<n;i++){
				j[i]=a[i]-max(b[i],c[i]);
				if(j[i]<0){
					j[i]=1145141;
				}
			}
		}else if(bsum>n/2){
			zdz=bsum;
			for(int i=0;i<n;i++){
				j[i]=b[i]-max(a[i],c[i]);
				if(j[i]<0){
					j[i]=1145141;
				}
			}
		}else{
			zdz=csum;
			for(int i=0;i<n;i++){
				j[i]=c[i]-max(a[i],b[i]);
				if(j[i]<0){
					j[i]=1145141;
				}
			}
		}
		sort(j,j+n);
		for(int i=0;i<zdz-(n/2);i++){
			ans-=j[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
