#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
long long q=0;
bool sz[10010][10010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int lu[10010][5],cun[20][10010];
	for(int i=1;i<=m;i++){
		cin>>lu[i][0]>>lu[i][1]>>lu[i][2];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++){
			cin>>cun[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=1;j<m-i;j++){
			if(lu[j][2]>=lu[j+1][2]){
				swap(lu[j][2],lu[j+1][2]);
				swap(lu[j][1],lu[j+1][1]);
				swap(lu[j][0],lu[j+1][0]);
			}
		}
	}
	cout<<lu[1][2]+lu[2][2]+lu[3][2]<<endl;
	return 0;
}
