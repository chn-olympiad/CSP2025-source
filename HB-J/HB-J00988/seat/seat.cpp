#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string d;
    int r;
    for(int i=1;i<=n*m;i++)
    {
        int a;
        cin>>a;
        d[i]=a;
        if(i=1)
        {
            r=a;
        }
    }
    for(int i=0;i<d.size();i++)
    {
        for(int j=0;j<d.size()-1;j++)
        {
            if(d[j]<d[j+1])
            {
                swap(d[j],d[j+1]);
            }
        }
    }
    int r_;
    for(int i=0;i<d.size();i++)
    {
        if(r=d[i])
        {
            r_=i;
            break;
        }
    }
    if(r_/n%2==0)
    {
        if(r_%n==0)
        {
            cout<<r_/n<<" "<<1;
            return 0;
        }
        else
        {
            cout<<r_/n+1<<" "<<n+1-r_%n;
            return 0;
        }
    }
    else
    {
        if(r_%n==0)
        {
            cout<<r_/n<<" "<<"4";
        }
        else
        {
            cout<<r_/n+1<<" "<<r_%n;
        }
    }
    return 0;
}