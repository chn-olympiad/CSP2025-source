#include<bits/stdc++.h>
using namespace std;
int a[100001],s[1001][1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1); 
	for(int i=1;i<=n*m/2;i++){
		int l=0;
		l=a[i];
		a[i]=a[n*m+1-i];
		a[n*m+1-i]=l;
	}
			
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			s[j][i]=a[(i-1)*n+j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j%2==0){
				for(int k=1;k<=n-1;k++){
					if(s[k][j]>s[k+1][j]){
						swap(s[k][j],s[k+1][j]);
					}
				} 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==p){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
