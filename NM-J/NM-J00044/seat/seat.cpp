#include <iostream>
#include <sort>
using namespace std;
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    frepone("seat.in","r",stdin);
    frepone("seat.out","w",stdout);
    int n,m,p;
    bool c=1;
    cin >> n >> m;
    int a[n*m+10]
    for(int i=0;i<=n*m;i++)
    {
        cin >> a[i];
    }
    p=a[0]
    sort(a,a+(n*m)+1,cmp);
    for(int i=0;c=0;i++)
    {
    	if (a[i]==p) 
    	{
    	    cout << i/n;
    	    cout << i%n;
    	}
    }
    return 0;
}
