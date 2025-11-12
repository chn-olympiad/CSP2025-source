#include <bits/stdc++.h>
using namespace std;
	int a[15][15];
	int cut[102];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c_R;
	cin>>c_R; //小R的成绩 
	int c_o=0;//其他比小R成绩高的人的数量 
	for(int i=1;i<n*m;i++){
		cin >> cut[i];
		if(cut[i]>c_R) c_o++;
	}
	int d=0;//d=0向下     d=1向上   d++转向 
	int i=1,j=1;
	for(int k=1;k<=c_o;k++){
		if(d==0) {
			if(i+1<=n) i++;
			else{
				d++;
				j++;
				continue;
			}
		}
		if(d==1) {
			if(i-1>=1) i--;
			else{
				d=0;
				j++;
			}
		}
	} 
	cout<<j<<" "<<i; 
	return 0;	
}
           
