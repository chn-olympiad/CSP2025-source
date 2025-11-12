#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,a[N][4],lim,rs[4]={0},val[N][4]={0},zt[4]={0},xz[N];
bool pd(){
	bool flag=1;
	for(int i=1;i<=3;i++){
		if(rs[i]>lim){
			flag=0;
		}
	}
	if(flag){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=0;j<=3;j++){
			rs[j]=0;
			zt[j]=0;
		}
		cin>>n;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				cin>>a[j][k];
			}
		}
		for(int j=1;j<=n;j++){
			int max_val_j=-1,xb=-1;
			for(int k=1;k<=3;k++){
				if(a[j][k]>max_val_j){
					max_val_j=a[j][k];
					xb=k;
				}
			}
			xz[j]=xb;
			rs[xb]++;
		}
		lim=n/2;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=3;k++){
				val[j][k]=a[j][k]-a[j][xz[j]];
			}
		}
		while(!pd()){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=3;k++){
					val[j][k]=a[j][k]-a[j][xz[j]];
				}
			}
			for(int j=1;j<=3;j++){
				if(rs[j]<lim){
					zt[j]=1;
				}
				if(rs[j]==lim){
					zt[j]=2;
				}
			}
			int max_change_val=INT_MIN;
			int hp=-1,sp=-1;
			for(int j=1;j<=3;j++){
				if(zt[j]==1){
					for(int k=1;k<=n;k++){
						if(val[k][j]>max_change_val&&zt[xz[k]]==0){
							max_change_val=val[k][j];
							hp=k;sp=j;
						}
					}
				}
			}
			int ls=xz[hp];
			xz[hp]=sp;
			rs[ls]--;
			rs[sp]++;
		}
		int ans=0;
		for(int j=1;j<=n;j++){
			ans=ans+a[j][xz[j]];
		}
		cout<<ans<<'\n';
	}
	return 0;
}