#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N][3];
int sum[5];
int tot,tott=0,tottt,ans=0,b,toto;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		tot=n/2;
		ans=0;
		tottt=0;
		b=0;
		toto=0;
		for(int j=1;j<=3;j++){
			sum[j]=0;
		}
		for(int i=1;i<=n;i++){
			tott=0;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				if(tott<a[i][j]){
					toto=tott;
					tott=a[i][j];
					b=tottt;
					tottt=j;
				}
				else if(sum[tottt]==tot){
					tottt=b;
					tott=toto;
				}
			}
			if(a[i][2]==0&&a[i][3]==0){
				for(int k=1;k<=tot;k++){
					for(int l=1;l<=n;l++){
						tott=max(tott,a[l][1]);
						ans+=tott;
						a[l][1]=0;
						tott=0;
					}
				}
				break;
			}
			else if(a[i][1]==0&&a[i][3]==0){
				for(int k=1;k<=tot;k++){
					for(int l=1;l<=n;l++){
						tott=max(tott,a[l][2]);
						ans+=tott;
						a[l][2]=0;
						tott=0;
					}
				}
				break;
			}
			else if(a[i][2]==0&&a[i][1]==0){
				for(int k=1;k<=tot;k++){
					for(int l=1;l<=n;l++){
						tott=max(tott,a[l][3]);
						ans+=tott;
						a[l][3]=0;
						tott=0;
					}
				}
				break;
			}
			else if(a[i][3]==0){
				for(int k=1;k<=n;k++){
					for(int k1=1;k1<=n;k1++){
						tott=max(tott,a[k][1]+a[k1][1]);
					}
				}
			}
			sum[tottt]++;
			ans+=tott;
		}
		cout<<ans<<endl;
	}
	return 0;
}
