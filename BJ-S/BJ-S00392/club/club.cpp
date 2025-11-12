#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,a[N][3],ans,sum1,sum2,sum3,cnt1[N],cnt2[N],cnt3[N];
long long sec(int a,int b,int c)
{
    return a+b+c-max(a,max(b,c))-min(a,min(b,c));
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        sum1=sum2=sum3=ans=0;
        memset(cnt1,0,sizeof cnt1);memset(cnt2,0,sizeof cnt2);memset(cnt3,0,sizeof cnt3);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            ans+=max(a[i][1],max(a[i][2],a[i][3]));
            if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1])
            {
                sum1++;
                cnt1[sum1]=sec(a[i][1],a[i][2],a[i][3])-max(a[i][1],max(a[i][2],a[i][3]));
            }
            else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2])
            {
                sum2++;
                cnt2[sum2]=sec(a[i][1],a[i][2],a[i][3])-max(a[i][1],max(a[i][2],a[i][3]));
            }
            else
            {
                sum3++;
                cnt3[sum3]=sec(a[i][1],a[i][2],a[i][3])-max(a[i][1],max(a[i][2],a[i][3]));
            }
        }
        if(sum1>n/2)
        {
            sort(cnt1+1,cnt1+sum1+1);
            for(int i=sum1;i>n/2;i--) ans+=cnt1[i];
        }
        else if(sum2>n/2)
        {
            sort(cnt2+1,cnt2+sum2+1);
            for(int i=sum2;i>n/2;i--) ans+=cnt2[i];
        }
        else if(sum3>n/2)
        {
            sort(cnt3+1,cnt3+sum3+1);
            for(int i=sum3;i>n/2;i--) ans+=cnt3[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
