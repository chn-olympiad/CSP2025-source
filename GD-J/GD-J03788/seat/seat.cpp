#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;int x;
int yans=1,xans=1,a[130][130];
void find(int ax,int ay){
	if(x<a[ax][ay]){
		if(yans%2==1){
			xans++;
			if(xans>n){
				xans=n;
				yans++;
			}
		}
		else{
			xans--;
			if(xans<1){
				xans=1;
				yans++;
			}
		}
	}
}
signed main(){
	freopen("seat.cpp","r",stdin);
	freopen("seat.cpp","w",stdout);
	//int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1 && j==1)cin>>x;
			else {
				cin>>a[i][j];
				find(i,j);
			}
		}
	}
	cout<<yans<<" "<<xans;
	return 0;
} 
