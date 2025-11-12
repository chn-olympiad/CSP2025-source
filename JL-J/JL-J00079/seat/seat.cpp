#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int s[100005];
int n,m;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>s[i];
    int little_a=s[1],hiss=0;
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(s[i]==little_a)
        {
            hiss=i;
            break;
        }
    }
    int tn,tm,cnt=1;
    tn=tm=1;
    for(int i=1;;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                if(cnt==hiss)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
                cnt++;
            }
        }else
        {
            for(int j=n;j>=1;j--)
            {
                if(cnt==hiss)
                {
                    cout<<i<<' '<<j;
                    return 0;
                }
                cnt++;
            }
        }
    }
    return 0;
}
