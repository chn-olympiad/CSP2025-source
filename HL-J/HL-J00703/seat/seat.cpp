#include<bits/stdc++.h>
using namespace std;
int a[120];
int b[15][15];
//bool cmp(int x,int y){
//	return x>y;
//}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	int rx=a[1];//小r的成绩 
	int t=m*n;
	int rpai;
	sort(a+1,a+1+t,greater<int>());
	for(int i=1;i<=t;i++){
		if(a[i]==rx){
			rpai=i;
		}
	}
//	cout<<rpai<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1){
				if(j==1){
					b[i][j]=1;
				}else if(j%2==1){
					b[i][j]=(j-1)*n+1;
				}else b[i][j]=j*n;
			}else if(i%2==0){
				if(j%2==0) b[i][j]=b[i-1][j]-1;
				else b[i][j]=b[i-1][j]+1;
			}else{
				if(j%2==1) b[i][j]=b[i-1][j]+1;
				else b[i][j]=b[i-1][j]-1;
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<b[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==rpai){
				cout<<j<<" "<<i<<endl;
				break;
			}
		}
	}
	return 0;
}