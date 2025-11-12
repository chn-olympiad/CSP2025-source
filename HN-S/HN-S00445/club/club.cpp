#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	int a[3][10];
	scanf("d,d,d",&t,&n,&a);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]+a[i+1][j]+a[i+2][j]<a[i][j+1]+a[i+1][j+1]+a[i+2][j+1])
			{
				if(a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]>t){
				t=a[i][j+1]+a[i+1][j+1]+a[i+2][j+1];					
				}
			}
			if (a[i][j]+a[i+1][j]+a[i+2][j]>a[i][j+1]+a[i+1][j+1]+a[i+2][j+1]){
				if(a[i][j]+a[i+1][j]+a[i+2][j]>t){
				t=a[i][j]+a[i+1][j]+a[i+2][j];					
				}
			}
		}
	}
	printf("d",t);
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	return 0;
}
