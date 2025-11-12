#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][3],mxa[100005],cntmx[3];
int fl1,fl2,sum,p[100005];
struct cc
{
    int mx,ca;
}cmxa[100005];
bool cmp(cc aa,cc bb)
{
    return aa.mx<bb.mx;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(cntmx,0,sizeof(cntmx));
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cmxa[i].ca=i;
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            mxa[i]=max(a[i][0],max(a[i][1],a[i][2]));
            sum+=mxa[i];
            if(mxa[i]==a[i][0])
            {
                p[i]=0;
                cntmx[0]++;
                cmxa[i].mx=mxa[i]-max(a[i][1],a[i][2]);
            }
            else if(mxa[i]==a[i][1])
            {
                p[i]=1;
                cntmx[1]++;
                cmxa[i].mx=mxa[i]-max(a[i][0],a[i][2]);
            }
            else
            {
                p[i]=2;
                cntmx[2]++;
                cmxa[i].mx=mxa[i]-max(a[i][1],a[i][0]);
            }
        }
        fl1=3;
        for(fl2=0;fl2<3;fl2++)
        {
            if(cntmx[fl2]>n/2)
            {
                fl1=fl2;
                break;
            }
        }
        if(fl1-3)
        {
            sort(cmxa+1,cmxa+n+1,cmp);
            int cnt=cntmx[fl1]-n/2,i=1;
            while(cnt)
            {
                if(p[cmxa[i].ca]==fl1)
                {
                    sum-=cmxa[i].mx;
                    cnt--;
                }
                i++;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}