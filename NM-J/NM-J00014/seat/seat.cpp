
#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int wei,yu,a[101],o=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cin>>a[o];
            o++;
        }
    }
    o--;
    int r=a[1];
    sort(a+1,a+o+1,cmp);
	for(int i=1;i<=o;i++)
    {
        if (a[i]==r)
        {
            wei=i;
            break;
        }
    }
    if (wei%n==0)
    	yu=n;
    else
    	yu=wei%n;
    if (wei%n!=0)
    {
    	wei=wei/n+1;
	}
	else
	{
		wei=wei/n;
	}
    cout<<wei<<" ";
    if (wei%2!=0)
    {
     	cout<<yu;
    }
    else
    {
    	cout<<n-yu+1;
	}
    return 0;
}
