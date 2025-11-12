#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
using namespace std;
int b[11][11],a[101];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	int m,n,z=1,h;
	cin>>m>>n;
	
	for(int i=1;i<=m;i++){
	for(int j=1;j<=n;j++){
	cin>>b[i][j];
	a[z]=b[i][j];
	z++;
	}}
	for(int i=1;i<=121;i++){
	for(int j=1;j<=z-1;j++){
	if(a[j]<a[j+1]){
		h=a[j];
		a[j]=a[j+1];
		a[j+1]=a[j];
	}
	}
	}
	int c;
	for(int i=1;i<=m*n;i++){
	if(a[i]==b[1][1]){
		c=i;
	}}
	int cy,qy;
	qy=c%m;
	if(cy%2==0&&qy!=cy){
	cout<<cy+1<<qy;	
	}else if(cy%2==0&&qy==0){
	cout<<cy<<"1";	
	}else if(cy%2!=0&&qy==0){
	cout<<cy<<n;	
	}else if(cy%2==0&&qy!=0){
	cout<<cy+1<<n-qy;
	}
	return 0;
}