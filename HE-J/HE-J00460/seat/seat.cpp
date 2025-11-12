#include<bits/stdc++.h>
using namespace std; 
int a[100][100],n=0,m=0,c=1,r=1,s;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]<a[i][j-1]||a[i][j]<a[i-1][j]){
				swap(a[i][j],a[i][j-1]);
			}
		}
	}
	s=a[1][1];
	for(int i=1;i<=n;i++){
		if(i%2==1){
			r=1;
			for(int j=1;j<=m;j++){
				if(a[i][j]==s){
					cout<<c<<" "<<r;
					return 0;
				}
				r++;
			}
		}
		if(i%2==0){
			r=5;
			for(int j=m;j>=1;j--){
				if(a[i][j]==s){
					cout<<c<<" "<<r;
					return 0;
				}
				r++;
			}
		}
		c++; 	
	}
	return 0;
}
