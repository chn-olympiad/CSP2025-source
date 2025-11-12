#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int a[101];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m>>a[1];
    int cnt=1;
    for(int i=2;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])
        {
            cnt++;
        }
    }
    int ansn,ansm;
    ansm=cnt/n;
    if(cnt%n!=0)
    {
        ansm++;
    }
    cout<<ansm<<" ";
    int r=cnt-(ansm-1)*n;
    if(ansm%2==1)
    {
        cout<<r;
    }
    else
    {
        cout<<n-r+1;
    }
    return 0;
}
