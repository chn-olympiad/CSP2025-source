#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

int n=0,k=0;
int a[200005];


int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cnt=n;

    for(int i=n;i>=1;i++)
    {
        for(int j=0;j<n-cnt+1;j++)
        {
            int ans=a[1];
            for(int k=2;k<=i;k++)
            {
                if(ans==a[k+j])
                {
                        ans=0;

                }
                else ans=1;

                if(ans==k)
                {
                    cout<<i<<endl;
                    return 0;

                }

            }
        }
        cnt--;
    }
    return 0;
}
