#include <bits/stdc++.h>
using namespace std;
int a[101],g[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	int nm=n*m;
	for(int i=1;i<=nm;i++){
		cin>>a[i];	
	}
	r=a[1];
	sort(a+1,a+1+nm,greater<int>());
	int x=1,y=1;
	for(int i=1;i<=nm;i++){
		g[x][y]=a[i];
		if(r==a[i]){
			cout<<x<<" "<<y;
			break;
		}
		if(((y==n)&&(x&1))||((y==1)&&(x%2==0))){
			x++;
		}else{
			if(x&1){
				y++;
			}else{
				y--;
			}
		}
	}
	return 0;
}
