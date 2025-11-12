#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int t,n,ans=0;
int f[N][N];
int c[N];
int a[N][N];
int st[N][N];
int max1,max2,max3,max4;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>f[i][1]>>f[i][2]>>f[i][3];
		}
		if(n==2){
			int ans=0;
				if(n==2){
					if((f[1][1]+f[2][2])>=f[1][1]+f[2][3]) max1=f[1][1]+f[2][2];
					else max1=f[1][1]+f[2][3];
					if((f[1][2]+f[2][1])>=f[1][3]+f[2][1]) max2=f[1][2]+f[2][1];		
					 if((f[1][2]+f[2][1])<f[1][3]+f[2][1]) max2=f[1][3]+f[2][1];
					max3=f[1][2]+f[2][3];
					max4=f[1][3]+f[2][3];
					if(max1!=max2){ans=max(max1,max2);}
					else ans=max1;
					if(ans!=max3){ans=max(ans,max3);}
					else ans=max3;
					if(ans!=max4){ans=max(ans,max4);}
					else ans=max4;
					}
			cout<<ans;
		
		}
		if(n==2){
			break;
		
		for(int i=1;i<=n;i++){
			int j=0;
			if(f[i][1]>f[i][2]&&f[i][1]>f[i][3]){
					j=1;a[i][j]=f[i][1];
			}
			
			if(f[i][1]<f[i][2]&&f[i][2]>f[i][3]){
					j=2;a[i][j]=f[i][2];
			}
			
			if(f[i][3]>f[i][2]&&f[i][3]>f[i][1]){
					j=3;a[i][j]=f[i][3];
			}
			st[i][j]=1;
		}
		
		c[1]=0;c[2]=0;c[3]=0;
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				if(st[j][i]==1) c[i]++;
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				if(c[i]<=(n/2)&&st[j][i]==1) ans=a[j][i]+ans;							
			}
		}
		cout<<ans;
	}
	}
		
	

	
	fclose(stdin);fclose(stdout);
	return 0;
}