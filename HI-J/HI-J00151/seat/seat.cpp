#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110],z;
void u(int x,int y,int f,int k){
	//cout<<z<<' '<<y<<' '<<x<<' '<<a[m*n-k]<<endl;
	if(a[n*m-k]==z){
		cout<<y<<' '<<x;
		return;
	}
	if(x==n && f==1){
		u(x,y+1,-1,k+1);
	}else if(x==1 && f==-1){
		u(x,y+1,1,k+1);
	}else{
		u(x+f,y,f,k+1);
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	z=a[1];
	sort(a,a+n*m+1);
	u(1,1,1,0);
	//freclose(stdin);
	//freclose(stdout);
	return 0;
}


