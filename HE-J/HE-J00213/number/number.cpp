#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	long long s;
	cin >> s;
	int b,c,p,q;
	if (s <10)
	{
		for(int i = 1;i<=s;i++)
		{
			b++;
		    if(b = s)
		    {
		    	cout << b;
			}
		break;
		}
    }
		p=(s/10);
		q=s%p;
		if(p>q)
		{
			cout << p << q;
		}
		if(p<q)
		{
			cout << q << p;
		}
	fclose (stdin);
	fclose (stdout);
	return 0;
}
