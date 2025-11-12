#include<bits/stdc++.h>
using namespace std;
//I don't know how to do it.
//How can it be so difficult!!!
int a[5005];
long long cnt;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int p=j+1;p<=n;p++)
            {
                int q=(a[p]+a[i]+a[j])/3;
                if(q>p&&q>j&&q>i)
                {
                    cnt++;
                    if(cnt>=998244353)
                    {
                        cnt-=998244353;
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
    //I'm the King Of Violenting Searching! (in T3)
}
//Why we don't need folder under the main folder toyear?
//Guess what?
//My Luogu name is TheLegendOfChen and welcome!!!
