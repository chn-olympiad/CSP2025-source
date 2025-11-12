//GZ-S00312 修文中学 王大为 

#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long a,b[]={0};
	long each[a][100000][5]={0};
	long sum=0;
	
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];
		for(int j=0;j<b[i];j++){
			for(int k=0;k<3;k++){
				cin>>each[i][j][k];
				sum+=each[i][j][k];
			}
		}
	}
	cout<<sum/2+;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
