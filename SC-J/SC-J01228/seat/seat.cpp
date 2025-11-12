#include<bits/stdc++.h>
using namespace std;
int n,a[15][15],m,x,b[110],p=1,y,z_=1;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	cin>>y;
	b[1]=y;
	for(int i=2;i<=x;i++){
		cin>>b[i];
		if(b[i]>y){
			p++;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=z_;
			z_++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==0){
			if(n%2==0){
				int k=n;
				for(int j=1;j<=n;j++){
					int l=a[i][j];
					a[i][j]=a[i][m];
					a[i][m]=l;
					k--;
				}
			}else{
				int k=n;
				for(int j=1;j<=n;j++){
					if(j=(1+m)/2){
						break;
					}
					int l=a[i][j];
					a[i][j]=a[i][m];
					a[i][m]=l;
					k--;
				}
			}
		}else{
			continue;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==p){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	return 0;
}