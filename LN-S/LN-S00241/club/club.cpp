#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001],mx[100001],id[100001],flag[100001],ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int u=n/2;
        int cnt1=0,cnt2=0,cnt3=0;
        bool f1=0,f2=0,f3=0;
        int m1=INT_MAX,m2=INT_MAX,m3=INT_MAX;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(cnt1=u)f1=1;
            if(cnt2=u)f2=1;
            if(cnt3=u)f3=1;
            if(a[i]>b[i]&&a[i]>c[i]&&!f1){
                cnt1++;
                ans+=a[i];
                m1=min(m1,a[i]);
            }
                if(b[i]>a[i]&&b[i]>c[i]&&!f2){
                cnt2++;
                ans+=b[i];
                m2=min(m2,b[i]);
            }
                if(c[i]>a[i]&&c[i]>b[i]&&!f2){
                cnt3++;
                ans+=a[i];
                m3=min(m3,c[i]);
            }
                if(f1&&a[i]>b[i]&&a[i]>c[i]){
                ans+=a[i]-m1;
            }
             if(f2&&a[i]>b[i]&&a[i]>c[i]){
                ans+=b[i]-m2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
