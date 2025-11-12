#include<bits/stdc++.h>
#define int long long
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define maxn 105
#define endl "\n"
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;


int a[maxn];


signed main()
{
	I AK CSP
	freopen ("seat.in" ,"r" ,stdin);
	freopen ("seat.out" ,"w" ,stdout);
	int n ,m;
	cin >> n >> m;
	for (int i = 1 ;i <= n * m ;i ++)
		cin >> a[i];
	int pm = 1;
	for (int i = 1 ;i <= n * m ;i ++)
		pm += (int)(a[i] > a[1]);
	int pastcol = pm / n ,currlin = pm % n;
	if (currlin == 0)
	{
		if (pastcol & 1)
			cout << pastcol << " " << n << endl;
		else
			cout << pastcol << " " << 1 << endl;
	}
	else
	{
		if (pastcol & 1)
			cout << pastcol + 1 << " " << n + 1 - currlin << endl;
		else
			cout << pastcol + 1 << " " << currlin << endl;
	} 
	return 0;
}//Code by Lyyq.
//wage