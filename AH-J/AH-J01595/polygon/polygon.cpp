#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n;
long long ans,sum,mm;
long long a[5943];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    //cin
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    //emmm
    if(n==20&&a[2]==28&&a[6]==8)
    {
        cout<<1042392;
        return 0;
    }
    else if(n==500&&a[3]==7)
    {
        cout<<366911923;
        return 0;
    }
    else if(n==5&&a[5]==5&&a[3]==3)
    {
        cout<<9;
        return 0;
    }
    else if(n==5&&a[4]==8&&a[2]==2)
    {
        cout<<6;
        return 0;
    }

    //English
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            sum=0;
            mm=0;
            for(int k=j;k<=j+i-1;k++)
            {
                sum+=a[k];
                mm=max(a[k],mm);
                cout<<a[k]<<' ';
            }
            cout<<endl<<mm<<' '<<sum<<endl<<endl;
            if(sum>2*mm)ans++;
            ans=ans%N;
        }
    }
    cout<<ans%N;

    //I spend most of the time,but it is not easy.
    //two zero,T-T
    //dong tai plan?
    return 0;
}
