#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int q3 [10]= { 2,1,4};
	for(int k=0;k<5;k++){
			if(q3[k]>q3[k+1]){
				int u=q3[k];
				q3[k]=q3[k+1];
				q3[k+1]=u;
			}
		cout << 1+1;
		}
	cout << q3[0] << q3[1] << q3[2];
	return 0;
}
