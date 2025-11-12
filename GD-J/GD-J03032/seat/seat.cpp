#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;


int a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >>n>>m;
	int alen=n*m;
	
	for (int i=1;i<=alen;i++)cin >>a[i];
	
	int xr=a[1],xrnum=1;
	
	for (int i=1;i<=alen;i++)if (a[i]>xr)xrnum++;
	
	
	int lei=ceil(1.0*xrnum/n);
	
	int pai=xrnum%n;
	if (pai==0)pai=n;
	
	if (lei%2==1){
		cout <<lei<<' '<<pai;
	}
	else {
		cout <<lei<<' '<<n-pai+1;
	}
	

	return 0;
} 
