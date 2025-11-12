//GZ-S00175 贵阳市第三中学 张轩哲 
#include<bits/stdc++.h>
using namespace std;
const int N=20;
int t,n,a[N],b[N],c[N]; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ma=INT_MIN;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i==1){
						if(j==2){
							ma=max(a[1]+b[2],ma);
						}else{
							ma=max(a[1]+c[2],ma);
						}
					}else if(i==2){
						if(j==1){
							ma=max(b[1]+a[2],ma);
						}else{
							ma=max(b[1]+c[2],ma);
						}
					}else{
						if(j==1){
							ma=max(c[1]+a[2],ma);
						}else{
							ma=max(c[1]+b[2],ma);
						}
					}
				}
			}
		cout<<ma<<endl;
		}
		if(b[1]==0){
			int ans=0;
			sort(a+1,a+1+n);
			for(int i=1;i<=n/2;i++){
				ans+=a[i];
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
