#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int x,y=0;
	cin >> x;
	int a[x];
	for(int i=0;i<x;i++) cin >> a[i];
	for(int i=3;i<=x;i++)
	{
		int b[i],sum=0;
		for(int o=0;o<i;o++) sum += b[o];
		if(sum > b.max()*2) y += 1;
	}
	cout << y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
