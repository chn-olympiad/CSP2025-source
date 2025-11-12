#include<bits/stdc++.h>
using namespace std;
int n,a[101010][5];
int ans;
int pf[101010];
int mx1,mx2,mx3;
int f[85][85][85];
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		for(int i=0;i<=80;i++)for(int j=0;j<=80;j++)for(int k=0;k<=80;k++)f[i][j][k]=0;
		mx1=mx2=mx3=0;
		memset(pf,0,sizeof(pf));
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)for(int j=1;j<=3;j++)scanf("%d",&a[i][j]);
		if(n==2){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j)ans=max(ans,a[1][i]+a[2][j]);
				}
			}
			printf("%d\n",ans);
			continue;
		}
		if(n==4){
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							if((i==j&&k!=l)||(i==k&&j!=l)||(i==l&&j!=k)||(j==k&&i!=l)||(j==l&&i!=k)||(k==l&&i!=j)){
								ans=max(ans,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
							}
						}
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		int fa=0;
		for(int i=1;i<=n;i++){
			if(a[i][2]!=0||a[i][3]!=0)fa=1;
			mx1=max(mx1,a[i][1]),mx2=max(mx2,a[i][2]),mx3=max(mx3,a[i][3]);
		}
		if(fa==0){
			for(int i=1;i<=n;i++)pf[i]=a[i][1];
			sort(pf+1,pf+n+1);
			for(int i=n;i>=n/2+1;i--)ans+=pf[i];
			printf("%d\n",ans);
			continue;
		}
		else{
			f[1][1][0]=mx1;
			f[1][0][1]=mx2;
			f[1][0][0]=mx3;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						int g=i-(j+k);
						if(j!=0&&g<=n/2)f[i][j][k]=max(f[i-1][j-1][k]+a[i][1],f[i][j][k]);
						if(k!=0&&g<=n/2)f[i][j][k]=max(f[i-1][j][k-1]+a[i][2],f[i][j][k]);
						if(g!=0&&g<=n/2)f[i][j][k]=max(f[i-1][j][k]+a[i][3],f[i][j][k]);
					}
				}
			}
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					if(n-(i+j)<=n/2&&n-(i+j)>=0)ans=max(ans,f[n][i][j]);
				}
			}
			printf("%d\n",ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
