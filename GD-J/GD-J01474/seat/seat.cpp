#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],cj,wz;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[(i-1)*n+j];
	cj=a[1];
	sort(a+1,a+1+n*m,[](int x,int y){
		return x>y;
	});
	for(int i=1;i<=n*m;i++){
		if(a[i]==cj){
			wz=i;
			break;
		}
	}
	int y=0,x=0;
	if(wz%n==0) y=wz/n;
	else y=wz/n+1;
	if(y%2==0){
		if(wz%n==0) x=1;
		x=m-wz%n+1; 
	}
	else{
		if(wz%n==0) x=n;
		else x=wz%n;
	} 
	cout<<y<<' '<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
