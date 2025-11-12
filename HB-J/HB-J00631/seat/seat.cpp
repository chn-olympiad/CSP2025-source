#include <bits/stdc++.h>
using namespace std;

int a[105];
int s[15][15];
int m,n,k;

bool f(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>m>>n;
	for (int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+m*n+1,f);
	
	int temp=1;
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (j%2!=0){
				s[i][j]=a[temp];
			}
			else if(j%2==0){
				s[i][j]=a[temp];
			}
			temp++;
		}
	}
	
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if (s[i][j]==k){
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	
	
	return 0;
}
//
