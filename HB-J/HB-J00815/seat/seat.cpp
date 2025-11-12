#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    bool flag=false;
    if(x>y)
    {
        flag=true;
    }
    return flag;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long m,n;
    cin>>n>>m;
    long long people=m*n;
    vector<int> ar(people+1);
    for(long long i=0;i<people;i++)
    {
        cin>>ar[i];
    }
    int fz=ar[0];
    sort(ar.begin(),ar.end(),cmp);
    for(long long i=0;i<people;i++)
    {
        if(ar[i]==fz)
        {
            fz=i+1;
            break;
        }
    }
    long long x=fz,y=1;
    if(fz>n)
    {
        y=fz/n+1;
        x=fz-(y-1)*n;
        if(y%2==0)
        {
            x=n-x+1;
        }
    }
    cout<<y<<' '<<x<<endl;
    return 0;
}
