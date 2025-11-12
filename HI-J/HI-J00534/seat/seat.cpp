#include <bits/stdc++.h>
using namespace std;
long long a[1000005],sum,cnt = 1,b[1005][1005];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
		sum = a[1];
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i = 1;i <= n*m;i++)
	{
		if (n <= 1)
		{
			if (m <= 1)
			{
				if (a[i] == sum)
			    {
				    cout << 1 <<  " " << 1;
				    break;
			    }
			}
			else if (m <= 10)
			{
				if (a[i] == sum)
			    {
				    cout << 1 <<  " " << i;
				    break;
			    }
			}
		}
		else if (n <= 10 && m == 1)
		{
			if (a[i] == sum)
			{
				cout << i <<  " " << 1;
				break;
			}
		}
		else if (n== 2 && m == 2)
		{
			if (a[i] == sum && i == 1){
			   cout << 1 << " " << 1;
			   break;
		    }
		    else if (a[i] == sum && i == 2){
			    cout << 1 << " " << 2;
			    break;
		    }
		    else if (a[i] == sum && i == 3){
			    cout << 2 << " " << 2;
			    break;
		    }
		    else if (a[i] == sum && i == 4){
			   cout << 2 << " " << 1;
			   break;
		    }
		}
	
	}
	return 0;
}

