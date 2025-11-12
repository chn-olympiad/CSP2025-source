#include<bits/stdc++.h>
using namespace std;
int m,n,a=0,b,c,i,j,l,q[111][5];
void aaa(){
	cin>>m;
	for (j=1;j<=m;j++){
		for (l=1;l<=3;l++){
			cin>>q[j][l];
		}
	}
}
int main (){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int  max[111];
	max[1]=0;
	cin>>n;
	for (i=1;i<=n;i++){
		aaa();
		for (j=1;j<=m;j++){
			for (l=1;l<=3;l++){
				if (max[j]<q[j][l]){
					max[j]=q[i][l];
				}	
			}
			a+=max[j];
		}	
		cout<<a-1;
	}
}
