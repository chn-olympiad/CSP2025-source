#include<bits/stdc++.h>
using namespace std;
	int a[100001],n,m,z,k,f;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++)cin>>a[i];
	f=a[1];
	sort(a+1,a+z+1);
	for(k=z;a[k]!=f;k--);
	k=z-k+1;
	int y,x=k/n,z=k%n;
	if(k%n!=0)x++;
	else z=n;
	if(x%2==1)y=z;
	else y=n-z+1;
	cout<<x<<" "<<y;
	return 0;
}
