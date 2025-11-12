#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rof(i,a,b) for(int i=a;i>=b;i--)
#define fs first
#define sc second
using namespace std;
const int N=1e5+5;
int n,t,a[N],b[N],c[N],kd[N];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    cin>>t;
    while(t--)
    {
        int ans=0,cnt1=0,cnt2=0,cnt3=0;
        cin>>n;
        For(i,1,n)cin>>a[i]>>b[i]>>c[i];
        For(i,1,n)
        {
            if(a[i]>=b[i]&&a[i]>=c[i])
            {
                kd[i]=1;
                ans+=a[i];
                cnt1++;
            }
            else if(b[i]>=a[i]&&b[i]>=c[i])
            {
                kd[i]=2;
                ans+=b[i];
                cnt2++;
            }
            else if(c[i]>=a[i]&&c[i]>=b[i])
            {
                kd[i]=3;
                ans+=c[i];
                cnt3++;
            }
            // cout<<i<<' '<<kd[i]<<endl;
        }
        int flg=0;
        if(cnt1>n/2)flg=1;
        if(cnt2>n/2)flg=2;
        if(cnt3>n/2)flg=3;
        if(!flg)
        {
            cout<<ans<<'\n';
            continue;
        }
        int cha=0,need=max(cnt1,max(cnt2,cnt3))-n/2;
        // cout<<need<<endl;
        vector<int>v;
        For(i,1,n)
        {
            if(flg==1&&kd[i]==1)v.push_back(min(a[i]-b[i],a[i]-c[i]));
            if(flg==2&&kd[i]==2)v.push_back(min(b[i]-c[i],b[i]-a[i]));
            if(flg==3&&kd[i]==3)v.push_back(min(c[i]-a[i],c[i]-b[i]));
        }
        sort(v.begin(),v.end());
        For(i,0,need-1)ans-=v[i];
        cout<<ans<<'\n';
    }
    return 0;
}