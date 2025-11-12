#include <bits/stdc++.h>
using namespace std;
long long n,m,k;
struct save_city{
    long long city_one=0;
    long long city_two=0;
    long long save_price=0;
    long long slt=0;
};
bool cmp(save_city a,save_city b)
{
    return a.save_price<b.save_price;
}
save_city a[11111];
long long b[20][1111111];
long long cou[20];
bool city[11111]={false};
bool city_d[11111];
long long minn1=0x3f3f3f,minn2=0x3f3f3f;
long long ts1,ts2;
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i].city_one>>a[i].city_two>>a[i].save_price;
    }
    for(int i=1;i<=k;i++)
    {
        cin>>cou[i];
        ts1=0,ts2=0;
        minn1=0x3f3f3f,minn2=0x3f3f3f;
        for(int j=1;j<=n;j++)
        {
            cin>>b[i][j];
            if(b[i][j]<minn1)
            {
                minn1=b[i][j];
                ts1=j;
            }
            else if(b[i][j]<minn2)
            {
                minn2=b[i][j];
                ts2=j;
            }
        }
        a[m+i].save_price=minn1+minn2+cou[i];
        a[m+i].city_one=ts1;
        a[m+i].city_two=ts2;
    }
    sort(a+1,a+m+k+1,cmp);
    for(int i=1;i<=m;i++)
    {
        bool vi=false;
        for(int i=1;i<=n;i++)
        {
            if(city[i]==true)
            {
                vi=true;
            }
            else
            {
                vi=false;
                break;
            }
        }
        if(city_d[a[i].city_one]<2&&city_d[a[i].city_two]<2&&vi==false)
        {
            ans+=a[i].save_price;
            city[a[i].city_one]=true;
            city[a[i].city_two]=true;
            city_d[a[i].city_one]++;
            city_d[a[i].city_two]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
