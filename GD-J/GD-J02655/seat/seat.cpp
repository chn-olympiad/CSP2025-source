#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[10005],b,c=1,d,e;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	b=a[1];
	for(int i=2;i<=n*m;i++)if(a[i]>b)c++;
	d=(c-1)/n+1;
	if(d==1||d%2==1)e=c-n*d+n;
	else e=n*d-c+1;
	cout<<d<<" "<<e;  
	fclose(stdin);
	fclose(stdout);
	return 0;
}
