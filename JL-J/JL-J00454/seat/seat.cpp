#include<bits/stdc++.h>
using namespace std;
int m,n,a[10000],cnt=-1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[10000];
    cin>>m>>n;
    int o=m*n;
    for(int i=0;i<o;i++)
    {
        cin>>a[i];
    }
    int k=a[0];
    for(int i=0;i<o-1;i++)
    {
        for(int j=0;j<o-i-1;j++)
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
    }
    int x;
    for(int i=0;i<o;i++)
    {
        if(a[i]==k)
        {
            x=i+1;
            break;
        }
    }
    int h=1,l=1;
    bool u=true;
    while(l!=m)
    {
        if(cnt==x)
        {
            cout<<l<<" "<<h;
            break;
        }
        if(h==n)
        {
            l++;
            u=false;
        }
        if(u==true)
        {
            h=h+1;
            cnt++;

        }
        if(u==false)
        {
            h=h-1;
            cnt++;

        }
        if(h==1)
        {
            l++;
            u=true;
        }
    }
    return 0;
}
