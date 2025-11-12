#include<bits/stdc++.h>
using namespace std;
int n,m;
int mp[15][15];
bool du=0;
int sor[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sor[i];
	}
	int duesor=sor[1];
	sort(sor+1,sor+1+n*m,cmp);
	int id=1;
	for(int i=1;i<=m;i++){
		if(!du){
			for(int j=1;j<=n;j++){
				mp[i][j]=sor[id];
				id++;
			}
			du=1;
		}else{
			for(int j=n;j>=1;j--){
				mp[i][j]=sor[id];
				id++;
			}
			du=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]==duesor){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
