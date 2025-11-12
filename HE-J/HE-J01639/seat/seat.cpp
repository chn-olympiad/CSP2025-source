#include<bits/stdc++.h>
using namespace std;
int n,m,a[11][11],x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]>=a[1][1])x++;
		}
	}
	cout<<(x-1)/m+1<<" ";
	if(((x-1)/m+1)%2){
		cout<<(x-1)%m+1;
	}
	else{
		cout<<m-((x-1)%m+1)+1;
	}
	return 0;
} 
