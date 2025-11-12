#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,a[10][100100][4];
void dfs(int x,int ceng,int sum,int q,int p1,int p2,int p3){
	for(int i=1;i<=3;i++){
		if(i==1){
			if(p1+1<=q/2){
				int sum1=sum+a[x][ceng][i];
				if(ceng+1<=q){
					dfs(x,ceng+1,sum1,q,p1+1,p2,p3);
				}
				else{
					if(sum1>a[10][1][1]) a[10][1][1]=sum1;
				}
			}
		}
		if(i==2){
			if(p2+1<=q/2){
				int sum1=sum+a[x][ceng][i];
				if(ceng+1<=q){
					dfs(x,ceng+1,sum1,q,p1,p2+1,p3);
				}
				else{
					if(sum1>a[10][1][1]) a[10][1][1]=sum1;
				}
			}
		}
		if(i==3){
			if(p3+1<=q/2){
				int sum1=sum+a[x][ceng][i];
				if(ceng+1<=q){
					dfs(x,ceng+1,sum1,q,p1,p2,p3+1);
				}
				else{
					if(sum1>a[10][1][1]) a[10][1][1]=sum1;
				}
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a[i][100011][1];
		for(int d=1;d<=a[i][100011][1];d++){
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][d][j]);
			}
		}
	}
	for(int i=1;i<=t;i++){
		int w=a[i][100011][1];
		a[10][1][1]=0;
		dfs(i,1,0,w,0,0,0);
		cout<<a[10][1][1]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
