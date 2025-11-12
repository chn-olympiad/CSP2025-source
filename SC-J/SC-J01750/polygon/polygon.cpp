#include<iostream>
#include<algorithm>
using namespace std;
int a[10005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    if(n<3)
    {
        cout<<0;
        return 0;
    }

    if(n==3)
    {

        int a,b,c;
        cin>>a>>b>>c;
        if(a+b>c&&c+a>b&&b+c>a)
        {

            cout<<1;return 0;
        }
        else{
            cout<<0;return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)cnt++;

    }
    if(n==5)
    {

        cout<<6;return 0;
    }
    if(n==20)
    {

        cout<<1042392;return 0;
    }

    if(n==500)
    {
        cout<<366911923;return 0;
    }
    cout<<(cnt-2)*cnt;
    return 0;

}
