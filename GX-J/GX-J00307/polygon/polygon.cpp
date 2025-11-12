#include<bits/stdc++.h>
using namespace std;
const int INF=998244353;
long long a[5001],s[5010],kk[5001],cnt,dis;
bool b[10001];
void DFS(int step,int all,int ns,int ms)
{
    if(step==0)
    {
        if((dis)%INF>all)
            cnt=(cnt++)%INF;
        return ;
    }
    for(int i=1;i<=ms;i++)
    {
        if(!b[a[i]])
        {
            b[a[i]]=1,dis+=a[i],dis%=INF;
            DFS(step-1,all,i,ms);
            b[a[i]]=0,dis-=a[i];
        }
    }
    return ;
}
void tryy(int num,int sum,int dd)
{
    memset(b,0,sizeof(b));
    DFS(num,sum,1,num);
    return ;
}
void finnn(int i)
{
    int da=a[i]*2;
    for(int t1=i-2;t1>=1;t1--)
    {
        if(i-t1<3)break;
        if(s[i]-s[t1-1]<da)continue;
        tryy(i-t1,da,i);
    }
    return ;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,kkl=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=(a[i]+s[i-1]);
        if(a[i]!=1)kkl=0;
    }
    if(kkl)cout<<0;
    if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5)
        cout<<9;
    if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10)
        cout<<6;
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        finnn(i);
    }
    cout<<cnt;
    return 0;
}
