#include <iostream>
#include <cmath>
using namespace std;

int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w".stdout);
	int n,m;
    cin >> n >> m;
    int sum=n*m;
    for(int i=1;i<=sum;i++)
    {
        cin >> a[i];
    }
    int l=a[1];
    sort(a+1,a+sum+1);
    int k=1;
    double x;
    for(int i=1;i<=sum;i++)
    {
        if(a[i]==l)
        {
            x=i;
            break;
        }
    }
    int y=x%n;
    int c=ceil(x/n);
    int r;
    if(y==0)
    {
        if(c%2==0)
        {
            r=1;
        }
        else
        {
            r=n;
        }
        cout << c << " " << r;
        return 0;
    }

    if(c%2==0)
    {
        r=n-y+1;
    }
    else
    {
		r=x/c;
    }
    cout << c << " " << r;
    return 0;
}
