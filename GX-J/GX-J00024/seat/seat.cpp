#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1],b;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==b)
        {
        if(i%m==0)
        {
            if(i%2*m>m)
            {
            cout<<i/m<<" "<<m;
            break;
            }
            else{
            cout<<i/m<<" "<<i%m+m;
            break;
            }
        }
        else {
            if(i%2*m>m)
            {
                cout<<floor(i/m)+1<<" "<<m-i%m+1;
                break;
            }
            else{
                cout<<floor(i/m)+1<<" "<<i%m;
                break;
            }
        }
        }
    }
    return 0;
}
