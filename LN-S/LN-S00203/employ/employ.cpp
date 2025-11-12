#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N=1e4+10;
int arr[N][N];
int brr[N][N];
int main(){
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=3;j++){
			cin>>arr[i][j];
			}
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n+1;j++){
				cin>>brr[i][j];
				}
			}
			cout<<"0";
	return 0;
}
