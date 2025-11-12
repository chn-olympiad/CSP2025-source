#include<bits/stdc++.h>
using namespace std;
struct xr{
	int fs;
	string name;
};
xr s[100][100];
xr a[1005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1].fs;
	a[1].name="xr";
	for(int i=2;i<=n*m;i++){
		
			cin>>a[i].fs;
			a[i].name="xm";
	
	}
	for(int i=n*m-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(a[j].fs<a[j+1].fs){
				swap(a[j],a[j+1]);
			}
		}
	}
	int z=1;
	for(int i=1;i<=m;i++){
		if(i%2!=0){
			for(int j=1;j<=n;j++){
				s[i][j]=a[z];
				z++;
			}
		}
		else{
			for(int j=n;j>=1;j--){
				s[i][j]=a[z];
				z++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s[i][j].name=="xr"){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}


