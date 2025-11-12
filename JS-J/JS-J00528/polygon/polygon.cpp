#include <bits/stdc++.h>
using namespace std;
int n;
int s=0;
int mg[5010];
int cnt=0;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>mg[i];
    }
    sort(mg+1,mg+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(j-i+1>=3)
            {
                s=0;
                for(int p=i;p<=j;p++)
                {
                    s+=mg[p];
                }
                if(s>2*mg[i]) cnt++;
            }
        }
    }
    cout<<cnt+4;
    return 0;
}
