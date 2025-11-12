#include <bits/stdc++.h>
using namespace std;

int n,m,a[105],r;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;

	int sum = n*m;

	for(int i=1;i<=sum;i++)
	{
		cin >> a[i];
	}
	r = a[1];

	sort(a+1,a+sum+1,cmp);

	for(int i=1;i<=sum;i++)
	{
		if(a[i]==r)
		{
			r = i;
			break;
		}
	}

	int ansc = (r / n);//第c列
	int ansr = (r % n);//第r行

	if(ansr != 0)
    {
        ansc++;
    }


    if(ansc%2==0)
    {
        if(ansr == 0)
        {
            ansr = 1;
        }
        else
        {
            ansr = n-ansr+1;
        }
    }
    else
    {
        if(ansr == 0)
        {
            ansr = n;
        }
    }

	cout << ansc << " " << ansr;

	return 0;
}
