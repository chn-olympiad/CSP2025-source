#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[15];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int v[15][15];
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(a[i]<a[j]){
				v[i][j]=a[j];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i]==a[1]){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
