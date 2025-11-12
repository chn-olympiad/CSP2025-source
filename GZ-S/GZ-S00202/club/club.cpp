//GZ-S00202 安顺市长水大洋实验学校 普嘉奥 
#include<bits/stdc++.h> 
using namespace std;
int main(){
	int sum=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int m,i,j,k,a[10000],x[100][100],y[100][100],z[100][100],t=0;
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>a[i];
			for(j=1;j<=a[i];j++){
				cin>>x[i][j]>>y[i][j]>>z[i][j];
			}
		sort(x[i]+1,x[i]+a[i]+1,greater<int>());
		sort(y[i]+1,y[i]+a[i]+1,greater<int>());
		sort(z[i]+1,z[i]+a[i]+1,greater<int>());
	} 
	
			
	for(i=1;i<=m;i++){
		for(j=1;j<=a[i];j++){
			t=0;
			if(x[i][a[i]/2+1]==0 && x[i][a[i]/2+2]==0 && x[i][a[i]/2+3]==0 && x[i][a[i]/2+4]==0){
				x[i][1]=0;
			}
			if(y[i][a[i]/2+1]==0 && y[i][a[i]/2+2]==0 && y[i][a[i]/2+3]==0 && y[i][a[i]/2+4]==0){
				y[i][1]=0;
			}
			if(z[i][a[i]/2+1]==0 && z[i][a[i]/2+2]==0 && z[i][a[i]/2+3]==0 && z[i][a[i]/2+4]==0){
				z[i][1]=0;
			}
			if(x[i][1]>=y[i][1] && x[i][1]>=z[i][1] && t!=1)
			{
				sum=sum+x[i][1];
				for(k=1;k<=a[i];k++){
					x[i][k]=x[i][k+1];
				}
				t=1;
			}
			if(y[i][1]>=x[i][1] && y[i][1]>=z[i][1] && t!=1)
			{
				sum=sum+y[i][1];
				for(k=1;k<=a[i];k++){
					y[i][k]=y[i][k+1];
				}
				t=1;
			}
			if(z[i][1]>=y[i][1] && z[i][1]>=x[i][1] && t!=1)
			{
				sum=sum+z[i][1];
				for(k=1;k<=a[i];k++){
					z[i][k]=z[i][k+1];
				}
				t=1;
			}
			
		}
		cout<<sum<<endl;
		sum=0;	
	}
	return 0;
} 
