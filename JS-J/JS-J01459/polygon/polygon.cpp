#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polyogn.out","w",stdout);

    int n;
    int a[5005];
    cin>>n;
    if(n<=2)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n==3)
    {
        cout<<1<<endl;
        return 0;
    }
    int kkk=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        kkk+=a[i];
    }
    int ans=1;int kkk1;
    for(int i=n-1;i>=3;i++)
    {
        kkk1=kkk;
        for(int j=1;j<=i;j++)
        {
            kkk1-=a[j];
        }
    }




    cout<<endl;
    return 0;
}
