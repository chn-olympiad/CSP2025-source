#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,y;
int main(){
	int i;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int cnt=0;
	cin>>a[1];
	for(i=2;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1])cnt++;
	}
	x=1+(cnt/n);
	y=1+(cnt%n);
	if(x%2==0)y=n-y+1;
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
