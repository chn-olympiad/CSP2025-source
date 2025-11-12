#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],t;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[++t];
		}
	}
	int x=a[1],y;
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			y=n*m-i+1;
			break;
		}
	}
	if(y%m==0){
		cout<<y/m<<" ";
	}else{
		cout<<y/m+1<<" ";
	}
	if(y/m%2==1){
		if(y%m==0){
			cout<<n;
		}else{
			cout<<n-y%m+1;
		}
	}else{
		cout<<y%m;
	}
	return 0;
}
