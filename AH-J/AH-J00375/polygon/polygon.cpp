#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a,b,c,d,e;
	cin >> n;
	cin >> a >> b >> c >> d >> e;
	int sum = 0;
	if(a + b + c > a *2 && a + b + c > b * 2 && a + b + c > c * 2)
		sum++;
	else if(a + b + d > a * 2 && a + b + d > b * 2 && a + b + d > d * 2)
		sum++;
	else if(a + b + e > a * 2 && a + b + e > b * 2 && a + b + e > e * 2)
		sum++;
	else if(a + c + d > a * 2 && a + c + d > c * 2 && a + c + d > d * 2)
		sum++;
	else if(a + c + e > a * 2 && a + c + e > c * 2 && a + c + e > e * 2)
		sum++;
	else if(a + d + e > a * 2 && a + d + e > d * 2 && a + d + e > e * 2)
		sum++;
	else if(b + c + d > b * 2 && b + c + d > c * 2 && b + c + d > d * 2)
		sum++;
	else if(b + c + e > b * 2 && b + c + e > c * 2 && b + c + e > e * 2)
		sum++;
	else if(b + d + e > b * 2 && b + d + e > d * 2 && b + d + e > e * 2)
		sum++;
	else if(c + d + e > c * 2 && c + d + e > d * 2 && c + d + e > e * 2)
		sum++;
	else if(a + b + c + d > a * 2 && a + b + c + d > b * 2 && a + b + c + d > c * 2 && a + b + c + d > d * 2)
		sum++;
	else if(a + b + c + e > a * 2 && a + b + c + e > b * 2 && a + b + c + e > c * 2 && a + b + c + e > e * 2)
		sum++;
	else if(a + b + d + e > a * 2 && a + b + d + e > b * 2 && a + b + d + e > d * 2 && a + b + d + e > e * 2)
		sum++;
	else if(b + c + d + e > b * 2 && b + c + d + e > c * 2 && b + c + d + e > d * 2 && b + c + d + e > e * 2)
		sum++;
	else if(a + b + c + d + e > a * 2 && a + b + c + d + e > b * 2 && a + b + c + d + e > c * 2 && a + b + c + d + e > d * 2 && a + b + c + d + e > e * 2)
		sum++;
	cout<<sum;
	return 0;
}
