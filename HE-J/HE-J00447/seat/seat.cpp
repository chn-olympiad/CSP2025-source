#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105];
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	x=a[1];
	if(n==1&&m==1){
		cout<<a[1];
		return 0;
	}
	sort(a+1,a+n*m+1,cmd);
	for(int i=1;i<=n*m;i++){
	if(a[i]==x)x=i;
	}
	for(int i=1;i<=m;i++){
		if((x>(i-1)*n)&&(x<=(i*n))){
		cout<<i<<" ";
		if(i%2==1)cout<<x-(i-1)*n;
		else cout<<2*n-x+1;
		}
	}
	return 0;
}
