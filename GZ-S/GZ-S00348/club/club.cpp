//GZ-S00348 贵阳市第十八中学 田缮恺
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],ba[100005],ha,hb,hc,maxx,ans[10];
double pa,pb,pc;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
		for(int k=0;k<n;k++){
			pa+=a[k];pb+=b[k];pc+=c[k];
		}
		pa/=n;pb/=n;pc/=n;
		for(int p=0;p<n;p++){
			ba[p]+=(a[p]+b[p]+c[p])/3;
			maxx=a[p];maxx=max(maxx,b[p]);maxx=max(maxx,c[p]);
			if(maxx==a[p]&&ha<n/2&&a[p]>pa){
				ha++;
				ans[i]+=a[p];
			}else if(ha>n/2||maxx!=a[p]){
				if(b[p]>c[p]&&hb<n/2&&b[p]>pb){
					hb++;
					ans[i]+=b[p];

				}else if(hb>n/2||b[p]<=c[p]||b[p]==c[p]){
					hc++;
					ans[i]+=c[p];
				}
			}
			ba[p]=0;
		}
		if(ha+hb+hc<n&&a[n-1]>=ba[n-1]){
			ans[i]+=a[n-1]*(n-ha-hb-hc);
		}else if(ha+hb+hc<n&&b[n-1]>=ba[n-1]){
			ans[i]+=b[n-1]*(n-ha-hb-hc);
		}else if(ha+hb+hc<n&&c[n-1]>=ba[n-1]){
			ans[i]+=c[n-1]*(n-ha-hb-hc);
		}
		ha=hb=hc=0;
		pa=pb=pc=0;
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
