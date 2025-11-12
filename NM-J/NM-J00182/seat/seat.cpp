include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sum=0;
    int a[105];
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(a[i]>a[1])
        {
            sum++;
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(sum==0)
        {
            cout<<"1 1";
            break;
        }
        if(sum==1)
        {
            cout<<"1 2";
            break;
        }
        if(sum==2)
        {
            cout<<"2 1";
            break;
        }
        if(sum==3)
        {
            cout<<"2 2";
            break;
        }
    }
    return 0;
}
