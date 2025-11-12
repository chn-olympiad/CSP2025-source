#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
    if(a>b) return true;
    else return false;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m]={0};
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int num=a[0];
    sort(a,a+n*m,compare);
    double cnt=0;
    for(int i=0;i<n*m;i++)
    {
        if(a[i]==num)
        {
            cnt=i+1;
            break;
        }
    }
    int c,r;
    double c2;
    c=(int)cnt/n;
    c2=cnt/n;
    if(c!=c2) c++;
    r=cnt-(c-1)*n;
    if(c%2==0) r=n-r+1;
    cout<<c<<" "<<r;
    return 0;
}
