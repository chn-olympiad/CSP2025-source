#include<bits/stdc++.h>
using namespace std;
int a[1100];
int b[11][11];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	int s=a[1],zz=1;
	sort(a+1,a+1+z,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int l=1;l<=n;l++){
				b[i][l]=a[zz];
				zz++;
			}
		}
		else{
			for(int l=n;l>=1;l--){
				b[i][l]=a[zz];
				zz++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int l=1;l<=n;l++){
			if(b[i][l]==s){
				cout<<i<<' '<<l;
				return 0;
			}
		}
	}
	return 0;
}
