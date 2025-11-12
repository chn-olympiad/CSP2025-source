#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int f[100010][4];
int Map[100001][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int n;
	for(int q=1;q<=t;q++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=0;
				f[i][j]=0;
				Map[i][j]=0;
			}
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		f[1][1]=a[1][1];
		f[1][2]=a[1][2];
		f[1][3]=a[1][3];
		Map[1][1]=100;
		Map[1][2]=10;
		Map[1][3]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				int t=pow(10,3-j);
				t=Map[i-1][j]/t;
				if(t+1<=n/2){
					if(f[i-1][1]>f[i-1][2]&&f[i-1][1]>f[i-1][3]){
						f[i][j]=f[i-1][1]+a[i][j];
						Map[i][j]=Map[i-1][1]+pow(10,3-j);
					}else if(f[i-1][2]>f[i-1][1]&&f[i-1][2]>f[i-1][3]){
						f[i][j]=f[i-1][2]+a[i][j];
						Map[i][j]=Map[i-1][2]+pow(10,3-j);
					}else{
						f[i][j]=f[i-1][3]+a[i][j];
						Map[i][j]=Map[i-1][3]+pow(10,3-j);
					}
				}else{
					int maxa=f[i-1][j];
					for(int k=1;k<=i;k++){
						if(Map[k-1][j]/100!=Map[k][j]/100){
							if(a[k-1][j]<a[i][j]){
								maxa=max(maxa,maxa-a[k-1][j]+a[i][j]);
							}
						}
					}
					if(maxa>max(f[i-1][1],max(f[i-1][2],f[i-1][3]))){
						Map[i][j]=Map[i-1][j];
						f[i][j]=maxa;
					}else{
						if(j==1){
							if(f[i-1][2]>f[i-1][3]){
								f[i][j]=f[i-1][2]+a[i][j];
								Map[i][j]=Map[i-1][2]+10;
							}else{
								f[i][j]=f[i-1][3]+a[i][j];
								Map[i][j]=Map[i-1][3]+1;
							}
						}else if(j==2){
							if(f[i-1][1]>f[i-1][3]){
								f[i][j]=f[i-1][1]+a[i][j];
								Map[i][j]=Map[i-1][1]+10;
							}else{
								f[i][j]=f[i-1][3]+a[i][j];
								Map[i][j]=Map[i-1][3]+1;
							}
						}else{
							if(f[i-1][2]>f[i-1][1]){
								f[i][j]=f[i-1][2]+a[i][j];
								Map[i][j]=Map[i-1][2]+10;
							}else{
								f[i][j]=f[i-1][1]+a[i][j];
								Map[i][j]=Map[i-1][1]+1;
							}
						}
					}
				}
			}
		}
		cout<<max(f[n][1],max(f[n][2],f[n][3]))<<endl;
		 
	}
	return 0;
}