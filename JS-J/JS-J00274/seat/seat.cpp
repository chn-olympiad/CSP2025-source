#include <bits/stdc++.h>
using namespace std;
int n,m;//hang & lie
int arr[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int xrrrr;
	cin>>xrrrr;
	int cnt = 1;
	for(int i = 2;i <= (n * m);i++)
	{
		cin>>arr[i];
		if(arr[i] > xrrrr) cnt++;
	}
	//cout<<"cnt:"<<cnt<<endl;//
	int c,r;//lie & hang
	if(cnt % n == 0)//lie
	{
		c = cnt / n;
	}
	else c = (cnt / n) + 1;
	if(c % 2 != 0)//ji shu lie 1 3 5 7
	{
		r = cnt - n * (c - 1);
	}
	else//ou shu lie 2 4 6 8
	{
		r = n + 1 - (cnt - n * (c - 1));//
	}
	cout<<c<<" "<<r;
	return 0;
}
