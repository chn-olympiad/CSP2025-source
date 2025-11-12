#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100011],b[100011],c[100011],ch[100011];
pair<int,int>aa[100011];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int cnta=0,cntb=0,cntc=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            int x=max(a[i],max(b[i],c[i])),y;
            if(a[i]==x)
            {
                y=max(b[i],c[i]);
                cnta++;
            }
            else if(b[i]==x)
            {
                y=max(a[i],c[i]);
                cntb++;
            }
            else
            {
                y=max(b[i],a[i]);
                cntc++;
            }
            ch[i]=x-y;
            cnt+=x;
        }
        //cout<<cnta<<" "<<cntb<<" "<<cntc<<"\n";
        if(cnta>n/2)
        {
            int inow=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]>b[i]&&a[i]>c[i])
                {
                    inow++;
                    aa[inow]={ch[i],i};
                }
            }
            sort(aa+1,aa+inow+1);
            for(int i=1;i<=cnta-n/2;i++)
            {
                cnt-=ch[aa[i].second];
                //cout<<cnt<<" "<<i<<" "<<aa[i].second<<" "<<ch[aa[i].second]<<"\n";
            }
        }
        else if(cntb>n/2)
        {
            int inow=0;
            for(int i=1;i<=n;i++)
            {
                if(b[i]>a[i]&&b[i]>c[i])
                {
                    inow++;
                    aa[inow]={ch[i],i};
                }
            }
            sort(aa+1,aa+inow+1);
            for(int i=1;i<=cntb-n/2;i++)
            {
                cnt-=ch[aa[i].second];
            }
        }
        else
        {
            int inow=0;
            for(int i=1;i<=n;i++)
            {
                if(c[i]>b[i]&&c[i]>a[i])
                {
                    inow++;
                    aa[inow]={ch[i],i};
                }
            }
            sort(aa+1,aa+inow+1);
            for(int i=1;i<=cntc-n/2;i++)
            {
                cnt-=ch[aa[i].second];
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
