#include<bits/stdc++.h>
using namespace std;
int a[105],b[105];
bool cmd(int a,int b){
	return a>b;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,h;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			h=a[i];
		}
	}
	
	sort(a,a+n*m,cmd);
	for(int i=1;i<=n*m;i++){
		cout<<a[i]<<" ";
	}
	for(int i=1;i<=m+1;i++){
		for(int j=1;j<=n;j++){
			if(a[i*n+j]==h){
				cout<<i<<" "<<j;
				return 0;
			}
		}
		i++;
		for(int j=n;j>=1;j--){
			if(a[i*n+(4-j)]==h){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}