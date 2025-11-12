#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,j;
    cin>>n>>m;
    int a[n*m+5];
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if (i==1)
        {
            j=a[i];
        }
    }
    sort(a+1,a+n*m+1);
    int q=1,p=1;
    for (int i=n*m;i>=1;i--)
    {
        if(q%2==0&&q!=0)
        {
            p--;
            cout<<p<<" ";
        }
        else
        {
            p++;
            cout<<p<<" ";
        }
        if(p%m==0||p==1)
        {
            q++;
            
            cout<<q<<endl;
        }
        if(a[i]==j)
        {
            cout<<q<<" "<<p;
            break;
        }
    }
    return 0;
}