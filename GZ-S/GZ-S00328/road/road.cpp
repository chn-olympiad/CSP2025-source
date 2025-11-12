//GZ-S00328 贵阳市花溪区同为京学附属实验学校 王洪羿
#include<bits/stdc++.h>
using namespace std;
int const M=1e6+1; 
int n,m,k,c[4][M];	//城市数量、道路数量、乡镇数量,修路费用 ,
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=1;j<=3;j++){
			cin>>c[j][i];
		}
	}
		
	return 0;
}
