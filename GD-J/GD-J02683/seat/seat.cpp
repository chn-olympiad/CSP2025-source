#include<bits/stdc++.h>

using namespace std;
int maps[15][15];
int cut;
int n,m;

void findway(int cut){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(maps[i][j]==cut){
				cout<<i<<" "<<j;
				return ;
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[100005];

	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	cut=a[1];
	sort(a+1,a+1+n*m);
	// for(int i=1;i<=n*m;i++){
	// 	cout<<a[i]<<" ";
	// }
	int x=n*m,y=n+1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				maps[i][j]=a[x];

				x--;
			}
		}else{
			for(int j=n;j>=1;j--){
				maps[i][j]=a[x];
				x--;
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		cout<<maps[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	findway(cut);
	
	return 0;
}
