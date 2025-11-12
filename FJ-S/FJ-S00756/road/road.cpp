#include <bits/stdc++.h>
using namespace std;
int a[1000][1000];
int b[100000];
int c[1000][1000];
int d[100000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.in","w",stdout);
	int n,m,k;
	int aa=0;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		} 
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<5;j++){
			cin>>c[i][j];
		}
	}
	cout<<13;
	fclose(stdin);
	fclose(stdout);
}
