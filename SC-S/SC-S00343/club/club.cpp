#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],mm[100005],wm[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int p=1;p<=t;p++){
		int n,na=0,nb=0,nc=0;
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				wm[i]=1;
				mm[i]=a[i];
				na++;
			} 
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				wm[i]=2;
				mm[i]=b[i];
				nb++;
			} 
			else if(c[i]>=a[i]&&c[i]>=b[i]){
				wm[i]=3;
				mm[i]=c[i];
				nc++;
			} 
		}
		while(na>n/2){
			int mgap=20005,mmm=0,wwwmmm=0;
			for(int i=1;i<=n;i++){
				if(wm[i]==1){
					int se=max(b[i],c[i]);
					if(a[i]-se<mgap){
						mgap=a[i]-se;
						mmm=i;
						if(b[i]>=c[i]) wwwmmm=2;
						else wwwmmm=3;
					}
				}
			}
			wm[mmm]=wwwmmm;
			na--;
			mm[mmm]=max(b[mmm],c[mmm]);
		}
		while(nb>n/2){
			int mgap=20005,mmm=0,wwwmmm=0;
			for(int i=1;i<=n;i++){
				if(wm[i]==2){
					int se=max(a[i],c[i]);
					if(b[i]-se<mgap){
						mgap=b[i]-se;
						mmm=i;
						if(a[i]>=c[i]) wwwmmm=1;
						else wwwmmm=3;
					}
				}
			}
			wm[mmm]=wwwmmm;
			nb--;
			mm[mmm]=max(a[mmm],c[mmm]);
		}
		while(nc>n/2){
			int mgap=20005,mmm=0,wwwmmm=0;
			for(int i=1;i<=n;i++){
				if(wm[i]==3){
					int se=max(a[i],b[i]);
					if(c[i]-se<mgap){
						mgap=c[i]-se;
						mmm=i;
						if(a[i]>=b[i]) wwwmmm=1;
						else wwwmmm=2;
					}
				}
			}
			wm[mmm]=wwwmmm;
			nc--;
			mm[mmm]=max(a[mmm],b[mmm]);
		}
		for(int i=1;i<=n;i++){
			ans+=mm[i];
		}
		cout<<ans<<endl;
	} 
	return 0;
}