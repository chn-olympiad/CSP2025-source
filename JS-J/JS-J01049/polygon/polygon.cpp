#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long LL;
const int N=5e3+8,M=998244353;
int n,m,a[N],cs[N],ans=0;
bool cmp(int x,int y)
{
    return x>y;
}
void ch(int num,int pos,int use)
{
    if(num==0)
    {
        int t=1,sum=0;
        while(t<pos)
        {
            //cout<<cs[t]<<" ";
            sum+=cs[t];
            t++;
        }
        if(sum>2*cs[1])
        {
            ans++;
            ans%=M;
        }
    }
    for(int i=use;i<=n;i++)
    {
        if(n-i+1<num)
        {
            break;
        }
        cs[pos]=a[i];
        ch(num-1,pos+1,i+1);
    }
    return ;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=n;i>=3;i--)
    {
        memset(cs,0,sizeof(cs));
        ch(i,1,1);
        //cout<<ans<<endl;
    }
    /*for(int i=n;i>=3;i--)
    {
        for(int j=1;j<=;j--)
        {

        }
    }*/
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
