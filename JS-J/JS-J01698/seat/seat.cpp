#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int a[N];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int cnt=0;
    for (int i=1;i<=n*m;i++)
    {
        if (a[i]>a[1])
        {
            cnt++;
        }
    }
    cnt++;
    if (cnt%n==0)
    {
		if ((cnt/n)%2==0)
			cout<<cnt/n<<' '<<1;
		else
			cout<<cnt/n<<' '<<n;
    }else
    {
        if ((cnt/n+1)%2==0)
			cout<<cnt/n+1<<' '<<n-cnt%n+1;
		else
			cout<<cnt/n+1<<' '<<cnt%n;
    }
	return 0;
}
