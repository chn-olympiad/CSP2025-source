#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int a[N];
int a1[N][N];
int r;
int n,m;
int x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	for(int i=1;i<=n*m-1;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}int y=0;
	//for(int i=1;i<=n*m-1;i++){
	//	cout<<a[i]<<" ";
	//}
	int f=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(f%2==0){
				y++;
				a1[i][n-j+1]=a[y];
				//cout<<a1[i][n-j+1]<<endl;
				if(r>a1[i][n-j+1]){
					cout<<i<<" "<<n-j+1;
					return 0;
				}
			}else{
				y++;
				a1[i][j]=a[y];
				//cout<<a1[i][j]<<endl;
				if(r>a1[i][j]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		f+=1;
	}
	cout<<a1[2][2]<<endl;
	return 0;
}
//2 2 98 99 100 97
//
