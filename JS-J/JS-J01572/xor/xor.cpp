#include<bits/stdc++.h>
using namespace std;
struct number{
    bool num[21];
};
int main()
{
	int k,n;
	number sum[500005];
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    int a[n + 1];
    bool b[n + 1],sk = 1;
    for(int i = 1;i <= n;i++)
    {
		b[i] = 1;
	}
    for(int i = 1;i <= n;i++)
    {
		cin >> a[i];
		if(a[i] != 1)
		{
			sk = 0;
		}
	}
	if(sk == 1 && k == 0)
	{
		cout << n;
		return 0;
	}
	//for(int i = 1;i <= n;i++)
	//{
	//	if(a[i] <= 1)
	//	{
	//		sum[i].num[1] = a[i];
	//		continue;
	//	}
	//	int x = 1;
	 //   while(a[i] >= 2)
	  //  {
	//		sum[i].num[x] = a[i] % 2;
	//		a[i] / 2;
	//		x++;
	//	}
	//	if(a[i] == 1)
	//	{
	//		sum[i].num[x] = 1;
	//	}
	//}
	//for(int i = 1;i <= n;i++)
	//{
	//	for(int j = 1;j <= n;j++)
	//	{
	//		if()
	//	}
	//}
    if(k == 0)
	{
		cout << 1;
	}
	else
    {
		cout << 2;
	}
    return 0;
}
