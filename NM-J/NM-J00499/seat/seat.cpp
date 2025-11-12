#include<bits/stdc++.h>
using namespace std;
vector<int> a;
bool sx(int c,int d)
{
    return c>d;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,rs,rm;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        int b=0;
        cin>>b;
        a.push_back(b);
    }
    rs=a[0];
    sort(a.begin(),a.end(),sx);
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==rs)
        {
            rm=i+1;
            break;
        }
    }
    int rl,rh;
    if(rm%n==0)
    {
        rl=rm/n;
    }
    else
    {
        rl=rm/n+1;
    }
    if(rl%2==0)
    {

        if(rm%n==0)
        {
            rh=1;
        }
        else
        {
            rh=n-rm%n+1;
        }
    }
    else
    {

        if(rm%n==0)
        {
            rh=n;
        }
        else
        {
            rh=rm%n;
        }
    }
    cout<<rl<<" "<<rh;
    return 0;
}
