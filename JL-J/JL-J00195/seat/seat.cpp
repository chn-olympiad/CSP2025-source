#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[12][12];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int b=a[1][1];
	int c,d;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==b){
				c=i;d=j;
			}
		}
	}
	if(a[c][d]==n)cout<<"1"<<" "<<n;
	else{
		if(a[c][d]==n+1)cout<<'2'<<' '<<n;
		else{
			if(a[c][d]==2*n)cout<<'2'<<' '<<'1';
			else{
				if(a[c][d]==2*n+1)cout<<'3'<<' '<<'1';
				else{cout<<c<<' '<<d;}
			}
		}
	}
	return 0;
}
