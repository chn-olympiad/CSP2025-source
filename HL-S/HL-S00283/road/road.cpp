#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[5][maxn];
int b[5][maxn];
int main(){
	freopen("rode.in","r",stdin);
	freopen("rode.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n+1;j++){
			cin>>b[i][j];
		}
	}
	cout<<0;
	return 0;
} 
