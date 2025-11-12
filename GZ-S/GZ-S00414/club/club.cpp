//GZ-S00414,毕节市第一中学,谢楷婕
#include <bits/stdc++.h>
using namespace std;
int ans[110000],peo[110000][4],cj[3][4],zui=-999;
void club(int i);
void search(int maxp,int m,int ren);
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	club(i);
	}
    for(int i=1;i<=n;i++){
    	cout<<ans[i]<<endl;
	}
    return 0;
}
void club(int i){
	int m;
	cin>>m;
	int maxp=m/2;
	for(int t=1;t<=m;t++){
		for(int j=1;j<=3;j++){
			cin>>peo[t][j];
		}
	}
	ans[i]=search(maxp,m,1);
}
void search(int maxp,int m,int ren){
	int zui=-9999;
	int cu;
	for(int i=1;i<=3;i++){
		if(ren<=m && cj[2][i]<maxp){
			cj[1][i]+=peo[ren][i];
			cu=cj[1][1]+cj[1][2]+cj[1][3];
			cj[2][i]++;
			if(cu>zui){
				zui=cu;
			}
			search(maxp,m,ren+1);
			cj[1][i]-=peo[ren][i];
			cj[2][i]--;
		}
	}
}
