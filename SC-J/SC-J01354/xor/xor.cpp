#include<bits/stdc++.h>
using namespace std;
int t[500006];
int dp[2][500006];
int x[2][500006],y[2][500006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x1=0,y1=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>t[i];//输入 
	}
	for(int i=1;i<=n;i++){
		x[0][i]=i;
		y[0][i]=i;
	}
	int temp=1,cor=0;
	int m=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			dp[cor][j]=(dp[temp][j-1]^t[j]);
			x[cor][j]=x[temp][j-1];
			y[cor][j]=y[temp][j];
			if(dp[cor][j]==k){
				if((x[cor][j]>x1 && y[cor][j]>y1) ||
				   (x[cor][j]<x1 && y[cor][j]<y1)){
				   	x1=x[cor][j];
				   	y1=y[cor][j];
				   	m++;
					}
				    
			}
			swap(temp,cor);
		}
	}
	cout<<m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}