#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a,b,h;
    cin>>a>>b;
    vector<int>n;
    int x;
    for(int i=0;i<a*b;i++)
    {
        cin>>x;
        n.push_back(x);
    }
    x=n[0];
    sort(n.begin(),n.end(),greater<int>());
    int l=0,m=0,r=n.size()-1;
    while(l<=r)
    {
        m=(l+r)/2;
        if(n[m]==x)
        {
            h=m+1;
            break;
        }
        else if(n[m]>x)
        {
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    int s=h;
    if(h%a==0)
    {
        h/=a;
        if(h%2==0)
        {
            cout<<h<<" 1";
        }
        else{
            cout<<h<<" "<<a;
        }
    }
    else
    {
        s/=a;
        if(s%2==0)
        {
            cout<<s+1<<" "<<0+(h%a);
        }
        else
        {
            cout<<s+1<<" "<<a+1-(h%a);
        }
    }
    return 0;
}
