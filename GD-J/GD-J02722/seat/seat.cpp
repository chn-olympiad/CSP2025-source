#include<bits/stdc++.h>
using namespace std;
/*        RP++!        */
int n,m;
int f[105][105];
int ak[10005];
bool cmp(int x,int y){
	return x>y;
}
int xiao_R = 0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>ak[i];
	xiao_R = ak[1];
	sort(ak+1,ak+1+(n*m),cmp);
//	for(int i=1;i<=n*m;i++) cout<<ak[i];
//	cout<<"\n";
	int xt = 1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int temp1 = ak [xt++];
			if(i%2 == 1){
				f[j][i] = temp1;
			}else{
				f[n-j+1][i] = temp1;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<f[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j] == xiao_R){
				cout<<j<<" "<<i;
				break;
			}
		}
	}
	return 0;
}

