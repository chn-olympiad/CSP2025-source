#include <iostream>
#include <algorithm>
using namespace std;

int a[110];
bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int k;
    for(int i=1; i<=n*m; i++)
    {
        cin >> a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1,cmp);
    int r;
    for(int i=1; i<=n*m; i++)
    {
        if(a[i]==k)
        {
            r=i;
            break;
        }
    }
    int l=r/(n*2);
    int q=r%(n*2);
    int flag=0;
    if(q!=0)
    {
    	flag=1;
	}
    if(q>n)
    {
    	flag=2;
	}
    cout << l*2+flag << " ";
    if(flag==2)
    {
        cout << 2*n-q+1 << endl;
    }
    else if(flag==1)
    {
        cout<< q << endl;
    }
    else
    {
    	cout << q+1 << endl;
    	
	}
    return 0;
}

