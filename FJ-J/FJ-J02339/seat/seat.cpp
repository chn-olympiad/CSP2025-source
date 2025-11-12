#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	int n,m,p,x=1,y=1;
	cin>>n>>m;
	int a[n][m];
	int b[n][m]; 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (a[i][j]>a[0][0]){
				p++;
			}
		}
	}
	while(1){
		if(p>n){
			x++;
			y++;
			p-=n;
		}
		else{
			break;
		}
	}
	if(y%2==0){
		cout<<n-p+1<<' '<<y;
	}
	else{
		cout<<p<<' '<<y;
	}
	return 0;
}
