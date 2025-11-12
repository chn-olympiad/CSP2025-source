#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node
{
	int val,id;
}a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		a[i].id=i;
		cin >> a[i].val;
	}
	a[0].val=a[1].val;
	int Rrd=1,c;
	for(int i=1;i<=n*m;i++)
		if(a[i].val>a[0].val)
			Rrd++;
	//cout << "Rrd: " << Rrd;
	//cout << " a[0].val: " << a[0].val << endl;
	c=((Rrd-1)/n)+1;
	if(c%2==1)
		if(Rrd%n!=0)
			cout << c << ' ' << Rrd%n;
		else cout << c << ' ' << n;
	else
		if(Rrd%n!=0)
			cout << c << ' ' << n+1-(Rrd%n);
		else cout << c << ' ' << 1;
	return 0;
}