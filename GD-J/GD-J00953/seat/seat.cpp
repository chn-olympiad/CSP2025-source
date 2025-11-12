#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m,k=0,sum;
	int a[11][11],b[122];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
		sum=b[1];
	}
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k++;
			a[j][i]=b[k];
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]==sum){
				cout<<j<<" "<<i;
			}
		}
	}
	 
	return 0;
}

