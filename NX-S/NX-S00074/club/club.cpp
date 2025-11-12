#include <bits/stdc++.h>
using namespace std;
int a[10005],b[10005],c[10005],bumen[10005],chengdu[10005],dierc[10005],diyicha[10005],diercha[10005],disancha[10005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=n;i++)
        {
            int maxn=-1;
            if(a[i]>maxn) {maxn=a[i]; bumen[i]=1;chengdu[i]=a[i];dierc[i]=max(b[i],c[i]);}
            if(b[i]>maxn) {maxn=b[i]; bumen[i]=2;chengdu[i]=b[i];dierc[i]=max(a[i],c[i]);}
            if(c[i]>maxn) {maxn=c[i]; bumen[i]=3;chengdu[i]=c[i];dierc[i]=max(b[i],a[i]);}
        }
        sort(dierc+1,dierc+n+1);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=chengdu[i];
        }
        int fir=0,sec=0,thir=0;
        for(int i=1;i<=n;i++)
        {
            if(bumen[i]==1)
                fir++;
            else if(bumen[i]==2)
                sec++;
            else if(bumen[i]==3)
                thir++;
        }
        for(int i=1;i<=n;i++)
    {
        if(bumen[i]==1)
            diyicha[i]=chengdu[i]-dierc[i];
        if(bumen[i]==2)
            diercha[i]=chengdu[i]-dierc[i];
        if(bumen[i]==3)
            disancha[i]=chengdu[i]-dierc[i];
    }
        sort(diyicha+1,diyicha+n+1);
        sort(diercha+1,diyicha+n+1);
        sort(disancha+1,diyicha+n+1);
        if(fir>n/2)
        {
            int k=fir-n/2;
            for(int i=1;i<=k;i++)
            {
                sum-=diyicha[i];
            }
        }
        if(sec>n/2)
        {
            int k=sec-n/2;
            for(int i=1;i<=k;i++)
            {
                sum-=diercha[i];
            }
        }
        if(thir>n/2)
        {
            int k=thir-n/2;
            for(int i=1;i<=k;i++)
            {
                sum-=disancha[i];
            }
        }
        cout<<sum<<endl;
    }

    return 0;
}
