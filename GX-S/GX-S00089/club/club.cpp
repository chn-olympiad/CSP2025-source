#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20;

int t,n,a[N],cnt[4],fp[5][N],sum,ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof cnt);
        memset(fp,0,sizeof fp);
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            pair<int,int> a[4];
            cin>>a[1].first>>a[2].first>>a[3].first;
            a[1].second=1;a[2].second=2;a[3].second=3;
            sort(a+1,a+4);
            int wz=a[3].second,cz=a[2].first-a[3].first;
            sum+=a[3].first;
            //cout<<sum<<endl;
            cnt[wz]++;
            fp[wz][cnt[wz]]=cz;
        }
        for(int i=1;i<=3;i++)
            if(cnt[i])sort(fp[i]+1,fp[i]+cnt[i]+1);

        int x=0;
        for(int i=1;i<=3;i++)if(cnt[i]>n/2){x=i;break;}
        //cout<<x<<endl;
        if(x==0)cout<<sum<<endl;
        else
        {
            for(int i=cnt[x];i>n/2;i--)sum+=fp[x][i];
            cout<<sum<<endl;
        }
    }
    return 0;
}
