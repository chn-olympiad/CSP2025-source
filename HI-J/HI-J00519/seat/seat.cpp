#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,R;
	
	cin>>n>>m;
	long long a[n*m+66]={};
	int A[n+66][m+66];
	
	for(int i=1;i<=n*m;i++){
		
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+m*n+1,greater<int>());
	
//	for(int j=1;j<=n*n;j++){
//		cout<<a[j]<<" ";
//	}
	int tmp=1;
	for(int i=1;i<=m;i+=2){
		for(int j=1;j<=n;j++){
			A[j][i]=a[tmp];
			tmp++;
		}
		for(int j=n;j>0;j--){
			A[j][i+1]=a[tmp];
			tmp++;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(A[i][j]==R){
				cout<<j<<" "<<i;
			}
//			cout<<A[i][j]<<" ";
		}
//		cout<<endl;
		
	}
	
	return 0;
}
