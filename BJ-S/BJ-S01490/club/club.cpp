#include<bits/stdc++.h>
using namespace std;
int t,n,coutans,huan;
int a[100005],b[100005],c[100005];
int zuida[100005],ans[100005],tot1,tot2,tot3,cha[100005],chaa[100005];
bool chabiao[100005];
void solve(int bumen)
{
    for(int i=1;i<=n;i++)
    {
        if(zuida[i]!=bumen)
        {

            cha[i]=chaa[i]=0x3f3f3f3f;
        }
    }

    sort(chaa+1,chaa+n+1);

    for(int i=1;i<=n;i++)
    {
        if(zuida[i]!=bumen)
            continue;
        for(int j=1;j<=huan;j++)
        {
            if(chabiao[j]!=1&&cha[i]==chaa[j])
            {
                chabiao[j]=1;
                coutans-=cha[i];
                break;
            }
        }


    }
    for(int j=1;j<=huan;j++)
        {
            chabiao[j]=0;
        }
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            if(a[j]>=b[j]&&a[j]>=c[j])
            {
                zuida[j]=1;
                if(b[j]>=c[j])
                {
                    chaa[j]=cha[j]=a[j]-b[j];
                }
                else
                {
                    chaa[j]=cha[j]=a[j]-c[j];
                }
                coutans+=a[j];
                continue;
            }
            if(b[j]>=a[j]&&b[j]>=c[j])
            {
                zuida[j]=2;
                if(a[j]>=c[j])
                {
                    chaa[j]=cha[j]=b[j]-a[j];
                }
                else
                {
                    chaa[j]=cha[j]=b[j]-c[j];
                }
                coutans+=b[j];
                continue;
            }
            if(c[j]>=b[j]&&c[j]>=a[j])
            {
                zuida[j]=3;
                if(b[j]>=a[j])
                {
                    chaa[j]=cha[j]=c[j]-b[j];
                }
                else
                {
                    chaa[j]=cha[j]=c[j]-a[j];
                }
                coutans+=c[j];
                continue;
            }

        }
        for(int k=1;k<=n;k++)
            {
                ans[k]=zuida[k];
                if(ans[k]==1)
                {
                    tot1++;
                }
                if(ans[k]==2)
                {
                    tot2++;
                }
                if(ans[k]==3)
                {
                    tot3++;
                }
            }
            if(tot1>n/2)
            {
                huan=tot1-n/2;
                solve(1);
            }
            if(tot2>n/2)
            {
                huan=tot2-n/2;
                solve(2);
            }
            if(tot3>n/2)
            {
                huan=tot3-n/2;
                solve(3);
            }

            tot1=tot2=tot3=0;
            cout<<coutans<<endl;
            coutans=0;
    }
    return 0;
}