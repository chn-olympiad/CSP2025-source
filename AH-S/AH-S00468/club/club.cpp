#include<bits/stdc++.h>
using namespace std;
int t,n,mas,mai=0;
int satis[100000][3]={-1,-1,-1};
int zui[100000][2]={-1,-1};
int tuan[3],ren[3]={-1};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=0;j<n;j++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>satis[i][0]>>satis[i][1]>>satis[i][2];
		}
		for(int k=0;k<n;k++){
			mai=0;
			mas=-1;
			for(int j=0;j<3;j++){
				if(mas<satis[k][j]){
					mas=satis[k][j];
					mai=k;
				}
			}
			zui[k][0]=mas;
			zui[k][1]=mai;
		}
		for(int i=0;i<n;i++){
			tuan[zui[i][1]]+=zui[i][0];
		}
		cout<<tuan[0]+tuan[1]+tuan[2];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
