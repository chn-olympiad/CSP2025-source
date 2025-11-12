#include<bits/stdc++.h>

using namespace std;

int n,m,a[105];

bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
		cin >> a[i];
	int memo = a[1],idx = 1;
	sort(a+1,a+n*m+1,cmp);
	while(a[idx] != memo)
		idx++;
	int c = idx / n,r = idx % n;
	if(!r)
		r = n;
	else
		c++;
	cout << c << " ";
	if(c & 1)
		cout << r;
	else
		cout << n-r+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
