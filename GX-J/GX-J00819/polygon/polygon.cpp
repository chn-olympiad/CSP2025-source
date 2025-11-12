#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int a, e=0;
	cin >> a;
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	if(s1*s2*s3>s3*2)
		e++;
	if(s1*s2*s3>s2*2)
		e++;
	if(s1*s2*s3>s1*2)
		e++;
	cout << e;
	return 0;
}
