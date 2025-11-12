#include<bits/stdc++.h>

using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b=1,c;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n*m;i++)
    {
        if(a[i]>a[0])
        {
            b++;
        }
    }
    if(b%n==0)
    {

    c=b/n;
    cout<<b/n<<" ";
    }
    else
    {

    c=b/n+1;
    cout<<b/n+1<<" ";
    }
    b--;
    if(c%2==1)
    cout<<b%m+1;
    else
    {
        cout<<m-b%m;
    }
}
