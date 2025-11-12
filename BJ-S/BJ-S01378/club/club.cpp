#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],c[1005];
int f[1005];
int big(int a,int b,int c)
{
    int maxx=max({a,b,c});
    if(maxx==a) return 1;
    else if(maxx==b) return 2;
    else if(maxx==c) return 3;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        int cnt1=0,cnt2=0,cnt3=0;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            f[i]=big(a[i],b[i],c[i]);
            if(f[i]==1) cnt1++;
            else if(f[i]==2) cnt2++;
            else if(f[i]==3) cnt3++;
            ans+=max({a[i],b[i],c[i]});
            while((cnt1>(n/2))||(cnt2>(n/2))||(cnt3>(n/2)))
            {
                ans--;
                cnt1--;
                if(cnt1==0)
                {
                    cnt2--;
                    ans--;
                    if(cnt2==0)
                    {
                        cnt3--;
                        ans--;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//g++ -o club club.cpp -O2
//./club