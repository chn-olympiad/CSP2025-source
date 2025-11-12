#include <bits/stdc++.h>
using namespace std;

int a[3];

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        int sum=0;
        for(int j=1;j<=n;j++)
        {
            int maxx=0;
            for(int k=1;k<=3;k++)
            {
                cin>>a[k];
                if(a[k]>maxx)
                {
                    maxx=a[k];
                }
            }
            sum+=maxx;
        }
        cout<<sum<<endl;
    }
    return 0;
}
