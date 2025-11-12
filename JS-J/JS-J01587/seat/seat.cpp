#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt=1;
long long a[100005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int tag=a[1];
    for(int i=2;i<=n*m;i++)
    {
        if(a[i]>tag)
            cnt++;
    }
    int x=cnt/n;
    int y=cnt%n;
    if(x%2==0)
        cout<<x+1<<" "<<y<<endl;
    else
        cout<<x+1<<" "<<n-y+1<<endl;
    return 0;
}
