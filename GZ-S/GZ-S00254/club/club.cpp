//GZ-S00254 遵义航天高级中学 杨一诺 
#include <bits/stdc++.h>
using namespace std;
int n,t;
int a[100001][4];
int c[100001][4];
int max1[100001];
int mi;
int a1[4];
int num;
long long sum1,mx;
int k,y;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			c[i][1]=abs(a[i][1]-a[i][2]);
			c[i][2]=abs(a[i][2]-a[i][3]);
			c[i][3]=abs(a[i][1]-a[i][3]);
			for(int j=1;j<=3;j++){
				if(max1[i]<c[i][j]){
					max1[i]=c[i][j];
				}
			}
			
		}
			num=n/2;
			for(int i=1;i<=n;i++){
				mi=0;
				for(int j=1;j<=n;j++){
					if(mi<max1[j]){
						mi=max1[j];
						k=j;
					}
				}
				if(a1[1]<num&&a1[2]<num&&a1[3]<num){
					for(int j=1;j<=3;j++){
						if(mx<a[k][j]){
							mx=a[k][j];
							y=j;
						}
					}
					a1[y]++;
					sum1+=mx;
					mx=0;
					max1[k]=-1;
				}
				else if(a1[1]>=num&&a1[2]<num&&a1[3]<num){
					for(int j=2;j<=3;j++){
						if(mx<a[k][j]){
							mx=a[k][j];
							y=j;
						}
					}
					a1[y]++;
					sum1+=mx;
					mx=0;
					max1[k]=-1;
				}
				else if(a1[1]<num&&a1[2]<num&&a1[3]>=num){
					for(int j=1;j<=2;j++){
						if(mx<a[k][j]){
							mx=a[k][j];
							y=j;
						}
					}
					a1[y]++;
					sum1+=mx;
					mx=0;
					max1[k]=-1;
				}
				else if(a1[1]<num&&a1[2]>=num&&a1[3]<num){
					for(int j=1;j<=3;j+=2){
						if(mx<a[k][j]){
							mx=a[k][j];
							y=j;
						}
					}
					a1[y]++;
					sum1+=mx;
					mx=0;
					max1[k]=-1;
				}
				else if(a1[1]<num&&a1[2]>=num&&a1[3]>=num){
					sum1+=a[k][1];
					mx=0;
					max1[k]=-1;
				}
				else if(a1[1]>=num&&a1[2]<num&&a1[3]>=num){
					sum1+=a[k][2];
					mx=0;
					max1[k]=-1;
				}
				else if(a1[1]>=num&&a1[2]>=num&&a1[3]<num){
					sum1+=a[k][3];
					mx=0;
					max1[k]=-1;
				}
			}
			cout<<sum1<<endl;
			for(int i=1;i<=3;i++){
				a1[i]=0;
			} 
			num=0;
			sum1=0;
			mx=0;
		 
	}
	fclose(stdin);
	fclose(stdout);
}	 

