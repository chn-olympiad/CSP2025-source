#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,o,e=0;
	cin >> n >> m;
	o=n*m;
	int a[o];
	cin >> a[0];
	int x=a[0],y=1,z=1;
	for(int i=1;i<o;i++)
		cin >> a[i];
	for(int i=1;i<o;i++){
		if(a[i]>x)
			z++;
		if(z>n){
			y++;
			z=1;}}
	cout << y << ' '<< z;
	return 0;
}