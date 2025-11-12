#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	int aa;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m+1;i++){
		if(a[i]==x){
			aa=(n*m)-i+1;
		}
	}
	int b[n+1][m+1];
	int l=1;
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				b[i][j]=l;
				l++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				b[i][j]=l;
				l++;
			}
		}	
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(b[i][j]==aa){
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}