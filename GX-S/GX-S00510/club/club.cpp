#include <iostream>
using namespace std;
int sum=0,a[10005];
int main()
{
    freopen("club in","r",stdin);
    freopen("club out","w",stdout);
    int n,a,b,c;
    cin>>a>>b>>c;
    for(int i=1;i<=n;i++)
    {
        if(a<=n/2)
        {
            a+=1;
        }
        if(b<=n/2)
        {
            b+=1;
        }
        if(c<=n/2)
        {
            c+=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
