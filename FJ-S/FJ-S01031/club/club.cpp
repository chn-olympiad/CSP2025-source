#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],dy1[100005][5],dy2[100005][5],st[5],sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int maxn=0,minn=30000;
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				maxn=max(a[i][j],maxn);
				minn=min(a[i][j],minn);
			}
			for(int j=1;j<=3;j++){
				int maxwz,minwz,midwz;
				if(a[i][j]==maxn){
					maxwz=j;
				}else if(a[i][j]==minn){
					minwz=j;
				}else{
					midwz=j;
				}
				dy1[i][1]=a[i][maxwz]-a[i][midwz];
				dy2[i][1]=a[i][maxwz]-a[i][minwz];
				dy1[i][2]=maxwz;
				dy2[i][2]=midwz;
			}
		}
		for(int i=1;i<=n;i++){
			if((st[dy1[i][2]]+1)*2<=n){
				sum+=a[i][dy1[i][2]];
				st[dy1[i][2]]++;
			}else if((st[dy2[i][2]]+1)*2<=n){
				sum+=a[i][dy2[i][2]];
				st[dy2[i][2]]++;
			}else{
				for(int j=1;j<=3;j++){
					if((j!=dy1[i][2])&&(j!=dy2[i][2])){
						sum+=a[i][dy2[i][2]];
					}
				} 
			}
		}
		cout<<sum; 
	}
	return 0;
}
