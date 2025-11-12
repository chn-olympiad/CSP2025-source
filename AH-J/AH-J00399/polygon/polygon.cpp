#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
long long sum,b[5005];
int main(void)
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=2;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int k=0;
            while(k<=i-2)
            {
                //if(b[i]-b[k]>a[j])sum++;
                for(int p=k;p<i;p++)
                {
                    int q=p;
                    long long ans=0;
                    while(q<i)
                    {
                        ans=ans+a[q];
                        if(b[i]-b[k]-ans>a[j])sum++;
                        else break;
                        q++;
                    }
                }
                k++;
            }

        }
    }
    cout<<sum%998244353;
    return 0;
}
