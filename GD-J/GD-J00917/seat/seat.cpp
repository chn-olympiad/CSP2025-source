#include<bits/stdc++.h>
using namespace std;
long long n,m,nm[10002],mn[102][102],r,zt=0,xn=1,yn=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int yu=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		yu++;
		cin>>nm[yu];
	}
	r=nm[1];
	sort(nm+1,nm+1+yu);
	
	for(int i=1;i<=n*m;i++){
		mn[xn][yn]=nm[yu];
		yu--;
		if(xn==n&&mn[xn-1][yn]==0)zt=0;
		if(xn==n&&mn[xn-1][yn]!=0)zt=1;
		if(xn==1&&mn[xn+1][yn]==0)zt=2;
		if(xn==1&&mn[xn+1][yn]!=0)zt=3;
		if(zt==2)xn++;
		if(zt==0)xn--;
		if(zt==1||zt==3)yn++;
	}
	for(int i=1;i<=100;i++)for(int k=1;k<=100;k++)if(mn[i][k]==r){
		cout<<k<<" "<<i;
		break;
	}
	
	return 0;
} 

