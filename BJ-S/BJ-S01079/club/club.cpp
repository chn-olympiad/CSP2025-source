#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int number[200005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,tf;
    cin>>t;
    for (int i=0;i<t;i++)
    {
        cin>>n;
        for (int i=0;i<200005;i++)
            number[i]=0;
        int ans=0,cnt_a=0,cnt_b=0,cnt_c=0;
        for (int i=0;i<n;i++)
            cin>>a[i]>>b[i]>>c[i];

        for (int i=0;i<n;i+=1)
        {
            if (a[i]>=b[i])
            {
                if (a[i]>=c[i]) ans+=a[i],cnt_a++;
                else ans+=c[i],cnt_c++;
            }
            else{
                if (c[i]>b[i]) ans+=c[i],cnt_c++;
                else ans+=b[i],cnt_b++;
            }
        }
        int cnt=0;
        if (cnt_a>n/2) cnt=cnt_a,tf=1;
        if (cnt_b>n/2) cnt=cnt_b,tf=2;
        if (cnt_c>n/2) cnt=cnt_c,tf=3;
        if (cnt>n/2)
        {
            for (int i=0;i<n;i++)
            {
                int maxn=max(a[i],b[i]);
                maxn=max(maxn,c[i]);
                int cha=10000000;
                if (a[i]!=maxn && tf!=1)
                    cha=min(cha,maxn-a[i]);
                if (b[i]!=maxn && tf!=2)
                    cha=min(cha,maxn-b[i]);
                if (c[i]!=maxn && tf!=3)
                    cha=min(cha,maxn-c[i]);
                number[cha]++;
            }
            for (int i=0;i<2000005;i++)
            {
                if (cnt<=n/2) break;
                cnt-=min(cnt-n/2,number[i]);
                ans-=(min(cnt-n/2,number[i])*i);
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
