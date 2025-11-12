#include<bits/stdc++.h>
using namespace std;
int a[11][11],b=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	b=a[0][0];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[j][i]==b){
				cout<<a[j][i];
			}
		}
	}
	return 0;
}
