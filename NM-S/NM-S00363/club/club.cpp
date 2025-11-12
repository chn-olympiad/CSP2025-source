#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>

struct node{
	int name;
	int zhi;
};
using namespace std;

bool pai(node a,node b){
	return a.zhi > b.zhi;
}

const int maxn = 1e5+10;			
					
int main(){
    //freopen("task1.in","r",stdin);
    //freopen("task1.out","w",stdout);
	int t,n;
	cin>>t;
	int d[maxn][4];
	int yi,er,san;
	int zui[t];///////////////jieguo
	for(int ii = 0;ii<t;ii++){
		memset(d,0,sizeof d);
		cin>>n;
		for(int i = 0;i<n;i++){
			for(int j = 1;j<4;j++){
				cin>>d[i][j];
			}
		}// ‰»Î
		
		node x[n]; 
		for(int i = 0;i<n;i++){
			if((d[i][1]>=d[i][2]&&d[i][2]>=d[i][3])||(d[i][1]>=d[i][3]&&d[i][3]>=d[i][2])){
				yi += 1;
				
				if(yi>n/2){
					for(int j = 0;j<n;j++){
						x[i].zhi = d[j][1];
						x[i].name = j;
					}
					sort(x,x+n,pai);
						if(d[i][1]<x[n/2].zhi){
							yi=yi-1;//////////////////////jide
							if(d[i][2]>=d[i][3]){
									zui[ii] += d[i][2];
									er += 1;
									continue;
									
							}
							zui[ii] += d[i][3];
							san += 1;
							continue;	
						}
						else{
							yi=yi-1;//////////////////////jide
							if(d[x[n/2+1].name][2]>=d[x[n/2+1].name][3]){
									zui[ii] -= d[x[n/2+1].name][1];
									zui[ii] += d[x[n/2+1].name][2];
									er += 1;
									continue;
									
							}
							zui[ii] -= d[x[n/2+1].name][1];
							zui[ii] += d[x[n/2+1].name][3];
							san += 1;
							continue;
						}
						
				}
				zui[ii] += d[i][1];
				continue;
				
			}
				
			if((d[i][2]>=d[i][3]&&d[i][3]>=d[i][1])||(d[i][2]>=d[i][1]&&d[i][1]>=d[i][3])){
				er += 1;
				if(er>n/2){
					for(int j = 0;j<n;j++){
						x[i].zhi = d[j][2];
						x[i].name = j;
					}
					sort(x,x+n,pai);
						if(d[i][2]<x[n/2].zhi){
							er=er-1;//////////////////////jide
							if(d[i][1]>=d[i][3]){
									zui[ii] += d[i][1];
									yi += 1;
									continue;
									
							}
							zui[ii] += d[i][3];
							san += 1;
							continue;	
						}
						else{
							er=er-1;//////////////////////jide
							if(d[x[n/2+1].name][1]>=d[x[n/2+1].name][3]){
									zui[ii] -= d[x[n/2+1].name][2];
									zui[ii] += d[x[n/2+1].name][1];
									yi += 1;
									continue;
									
							}
							zui[ii] -= d[x[n/2+1].name][2];
							zui[ii] += d[x[n/2+1].name][3];
							san += 1;
							continue;
						}
						
				}	
				zui[ii] += d[i][2];
				continue;
			}
			if((d[i][3]>=d[i][1]&&d[i][1]>=d[i][2])||(d[i][3]>=d[i][2]&&d[i][2]>=d[i][1])){
				san += 1;
				if(san>n/2){
					for(int j = 0;j<n;j++){
						x[i].zhi = d[j][3];
						x[i].name = j;
					}
					sort(x,x+n,pai);
						if(d[i][3]<x[n/2].zhi){
							san=san-1;//////////////////////jide
							if(d[i][1]>=d[i][2]){
									zui[ii] += d[i][1];
									yi += 1;
									continue;
									
							}
							zui[ii] += d[i][2];
							er += 1;
							continue;	
						}
						else{
							san=san-1;//////////////////////jide
							if(d[x[n/2+1].name][1]>=d[x[n/2+1].name][2]){
									zui[ii] -= d[x[n/2+1].name][3];
									zui[ii] += d[x[n/2+1].name][1];
									yi += 1;
									continue;
									
							}
							zui[ii] -= d[x[n/2+1].name][3];
							zui[ii] += d[x[n/2+1].name][2];
							er += 1;
							continue;
						}
				}
				zui[ii] += d[i][3];
				continue;
			}*/
		}

	}		
	for(int i = 0;i<t;i++){
		cout<<zui[i]<<endl;
	}// ‰≥ˆ 

    return 0;
}


