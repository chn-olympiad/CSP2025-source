//GZ-S00492 贵州省实验中学 韩一鸣
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in",'r',stdin);
	freopen("road.out",'w',stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int zz[n][n];
	for (int i=0;i<m;i++){
		int a,s,d;
		cin>>a>>s>>d;
		zz[a][s]=d;
		zz[s][a]=d;
		zz[i][i]=0;
	}
	int cz[k][n];
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>cz[i][j];
		} 
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i!=j){
				int o=zz[i][j],p=zz[i][j+1]+zz[i+1][j];//,q=cz[0][i+1]+cz[0][j+1]+cz[0];
				zz[i][j]=min(o,p);
			}
		}
	}
	int mnn=1000000,sum=0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(i!=j && j!=n-2){
				int o=zz[i][j],p=zz[i][j+1];
				mnn=min(o,p); 
			}
		}
		sum+=mnn;
	} 
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
