#include<bits/stdc++.h>
using namespace std;
int a[400010];
int n,t,cntp,s;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n*3;++i)
        {
            cin>>a[i];
            if((i-1)%3!=0&&a[i]==0)
            ++cntp;
        }
        if(n==2)
        {
            for(int i=1;i<=3;++i)
            {
                for(int j=4;j<=6;++j)
                {
                    if((j-i)%3!=0)
                    s=max(a[i]+a[j],s);
                }
            }
            cout<<s;
            return 0;
        }
        
        if(cntp==n*2)
        {
            sort(a+1,a+n*3+1,greater<int>());
            for(int i=1;i<=n/2;++i)
            s+=a[i];
            cout<<s;
            return 0;
        }
    }
    return 0;
}