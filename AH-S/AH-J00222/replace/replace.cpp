#include<bits/stdc++.h>
using namespace std;
int tot = 0,n;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    for(int i = 1;i <= n;i++)
    {
		cin >> n;
		if(n % 2 == 1)
		{
		    cin >> n;
		    tot += n;	
		}
		else
		{
			cin >> a[i];
			tot += a[i] - n;
		}
		cout << " " << endl;
	}
    return 0;
}
