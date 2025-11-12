#include <bits/stdc++.h>
using namespace std;
int n,m;
int a1[105];
int a2[15][15];
int a3[105];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a1[i];
		a3[i]=a1[i];
	}
	for(int i=1;i<=n*m;i++){
		int tos=0;
		for(int j=i;j<=n*m;j++){
			if (a1[j] >= a1[i]) {
				tos=a1[i];
				a1[i]=a1[j];
				a1[j]=tos;//jiao huan
			}
		}
		//cout<<a1[i]<<" ";
	}
	//cout<<a3[1];
	int top=0;
	for(int i=1;i<=n;i++){
		if (i%2==1){
			for(int j=1;j<=m;j++){
				top++;
				a2[i][j]=a1[top];
				//cout<<a2[i][j]<<" ";
				//if (a2[i][j]==a3[1]){
				//	cout<<i<<" "<<j;
				//	break;
				//}
			}
		}
		else {
			for(int j=m;j>=1;j--){
				top++;
				a2[i][j]=a1[top];
				//cout<<a2[i][j]<<" ";
				//if (a2[i][j]==a3[1]){
				//	cout<<i<<" "<<j;
				//	break;
				//}
			}
		}
		//cout<<endl;
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			//a4[i][j]=a2[j][i];
			//cout<<a2[i][j]<<" ";
			if (a2[i][j]==a3[1]){
				cout<<i<<" "<<j;
				break;
			}
		}
		//cout<<endl;
	}
	//cout<<a2[1][1]<<endl;
	return 0;
}
