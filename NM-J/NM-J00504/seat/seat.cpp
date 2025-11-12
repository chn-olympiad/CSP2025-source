#include <bits/stdc++.h>
using namespace std;
int n,m,ans,sum,b,c,d,a[10086],zo,xr,tem;
bool bmp(int x,int y){
		return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	zo=n*m;
	for(int i=1;i<=zo;i++)
		cin>>a[i];
	xr=a[1];
	sort(a+1,a+zo+1,bmp);
	for(int j=1;j<=zo;j++){
		if(a[j]==xr){
			xr=j;
			break;
		}
	}
	tem=xr%n;
	sum=xr/n; 
	if(sum%2==1){
		if(tem==0)	cout<<sum<<' '<<n;
		else    cout<<sum+1<<' '<<n-tem+1;
	}
	else{
		if(tem==0)	cout<<sum<<' '<<1;
		else    cout<<sum+1<<' '<<tem;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
