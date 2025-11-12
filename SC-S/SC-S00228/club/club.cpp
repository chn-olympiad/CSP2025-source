#include<bits/stdc++.h>
using namespace std;
int t,n,a[305][4],cf[305][3],maxn[305],ans[4],sum[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		ans[1]=ans[2]=ans[3]=sum[1]=sum[2]=sum[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			cf[i][1]=abs(a[i][1]-a[i][2]);
			cf[i][2]=abs(a[i][2]-a[i][3]);
			cf[i][3]=abs(a[i][3]-a[i][1]);
			if(cf[i][1]>cf[i][2]&&cf[i][1]>cf[i][3]){
				maxn[i]=1;
			}else if(cf[i][2]>cf[i][1]&&cf[i][2]>cf[i][3]){
				maxn[i]=2;
			}else if(cf[i][3]>cf[i][1]&&cf[i][3]>cf[i][2]){
				maxn[i]=3;
			}else if(cf[i][1]==cf[i][2]&&cf[i][1]>cf[i][3]){
				maxn[i]=12;
			}else if(cf[i][1]>cf[i][2]&&cf[i][1]==cf[i][3]){
				maxn[i]=13;
			}else if(cf[i][2]>cf[i][1]&&cf[i][2]==cf[i][3]){
				maxn[i]=23;
			}else if(cf[i][1]==cf[i][2]&&cf[i][1]==cf[i][3]){
				maxn[i]=123;
			}
		}
		for(int i=1;i<=n;i++){
			if(maxn[i]==1){
				ans[1]+=a[i][1];
				sum[1]++;
			}else if(maxn[i]==2){
				ans[2]+=a[i][2];
				sum[2]++;
			}else if(maxn[i]==3){
				ans[3]+=a[i][3];
				sum[3]++;
			}else if(maxn[i]==12){
				if(sum[1]>sum[2]){
					ans[1]+=a[i][1];
					sum[1]++;
				}else{
					ans[2]+=a[i][2];
					sum[2]++;
				}
			}else if(maxn[i]==23){
				if(sum[3]>sum[2]){
					ans[3]+=a[i][3];
					sum[3]++;
				}else{
					ans[2]+=a[i][2];
					sum[2]++;
				}
			}else if(maxn[i]==13){
				if(sum[1]>sum[3]){
					ans[1]+=a[i][1];
					sum[1]++;
				}else{
					ans[3]+=a[i][3];
					sum[3]++;
				}
			}else{
				if(sum[1]>sum[2]&&sum[1]>sum[3]){
					ans[1]+=a[i][1];
					sum[1]++;
				}else if(sum[2]>sum[1]&&sum[2]>sum[3]){
					ans[2]+=a[i][2];
					sum[2]++;
				}else{
					ans[3]+=a[i][3];
					sum[3]++;
				}
			}
		}
		cout<<ans[1]+ans[2]+ans[3]<<'\n';
	}
	return 0;
}