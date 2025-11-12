#include<bits/stdc++.h>
using namespace std;
long long T,n,a,b,c;
long long maxx,minn,midd;
long long ans,sum;
bool bm1,bm2,bm3;
int tpp2;
int temp;
int tpp3;
int dp[100010];
int bm[4];
int tmp[4];
int tpa,tpb,tpc,tpd,tpe,tpf,tp1,tp2,tp3;
void tp()
{
    if(n==2)
    {
        cin>>tpa>>tpb>>tpc>>tpd>>tpe>>tpf;
        tp1=max(tpa+tpe,tpa+tpf);
        tp2=max(tpb+tpd,tpb+tpf);
        tp3=max(tpc+tpd,tpc+tpe);
        cout<<max(tp1,max(tp2,tp3))<<endl;
    }
}
void px(int x,int y,int z)
{
    maxx=max(x,max(y,z));
    if(maxx==x)
    {
        tmp[1]=1;
    }
    if(maxx==y)
    {
        tmp[1]=2;
    }
    if(maxx==z)
    {
        tmp[1]=3;
    }
    minn=min(x,min(y,z));
    if(minn==x)
    {
        tmp[3]=1;
    }
    if(minn==y)
    {
        tmp[3]=2;
    }
    if(minn==z)
    {
        tmp[3]=3;
    }
    if(x!=maxx&&x!=minn)
    {
        midd=x;
        tmp[2]=1;
    }
    if(y!=maxx&&y!=minn)
    {
        midd=y;
        tmp[2]=2;
    }
    if(z!=maxx&&z!=minn)
    {
        midd=z;
        tmp[2]=3;
    }
    return;
}
void change()
{
    bm1=0;
    bm2=0;
    bm3=0;
    temp=tmp[1];
    if(bm[tmp[1]]==n/2)
    {
        bm1=1;
        temp=tmp[2];
        if(bm[tmp[2]]==n/2)
        {
            bm2=1;
            temp=tmp[3];
        }
    }
    return;
}
int main()
{

    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        ans=0;
        cin>>n;
        if(n==2)
        {
            tp();
            continue;
        }
        tpp2=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a>>b>>c;
            px(a,b,c);
            if(c==0&&b==0)
            {
                tpp2++;
                dp[j]=a;
            }
//            cout<<maxx<<" "<<midd<<" "<<minn<<endl;
//            cout<<tmp[1]<<" "<<tmp[2]<<" "<<tmp[3];
            if(bm1==0)
            {
                ans+=maxx;
                bm2=1;
                bm3=1;
            }
            if(bm2==0)
            {
                ans+=midd;
                bm3=1;
            }
            if(bm3==0)
            {
                ans+=minn;
            }
        }
        if(tpp2!=n)
        {
            cout<<ans<<endl;
        }
        if(tpp2==n)
        {
            sort(dp+1,dp+n+1);
            for(int k=n;k>n/2;k--)
            {
                sum+=dp[k];
            }
            cout<<sum;
        }
    }
}
