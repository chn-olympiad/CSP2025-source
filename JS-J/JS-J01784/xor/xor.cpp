#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N][30];
bool vis[N];
int yh[30];
int bk[30];

int mxw;
void szr (int n,int j)
{
    int m=n;
    string s;
    while(n!=0)
    {
        char g=n%2+'0';
        s=s+g;
        n/=2;
    }
    int sz=s.size();
    mxw=max(mxw,sz-1);
    for(int i=sz-1;i>=0;i--)
    {
        a[j][19-i]=s[i]-48;
    }
}
void szr2 (int n)
{
    int m=n;
    string s;
    while(n!=0)
    {
        char g=n%2+'0';
        s=s+g;
        n/=2;
    }
    int sz=s.size();
    for(int i=sz-1;i>=0;i--)
    {
        bk[20-1-i]=s[i]-48;
    }
}
void yyh(int l,int r)
{
    for(int j=mxw;j<20;j++)
    {
        bool f=1;
        for(int i=l;i<=r;i++)
        {
            if(a[i][j]==0||a[i][j]==-1)
            {
                f=0;
                break;
            }
        }
        if(f)
        yh[j]=1;
    }

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
freopen("xor.in","r"`,stdin);
   freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n<=2&&k==0)
    {
        cout<<0;
        return 0;
    }else if(n<=10&&k<=1)
    {


    }
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        szr(num,i);
        /*
         for(int j=0;j<20;j++)
        {
            cout<<a[i][j];
        }
        cout<<'\n';
        */
    }
    memset(bk,-1,sizeof(bk));
    szr2(k);
    /*
    for(int i=0;i<20;i++)
    {
        cout<<bk[i];
    }
    */
   // cout<<'\n';
    int l=0,r=0;
    long long ans=0;
    while(l<n)
    {
        memset(vis,0,sizeof(vis));
        memset(yh,-1,sizeof(yh));
        for(r=l;r<n;r++)
        {
            cout<<'\n'<<l<<' '<<r<<'\n';
            yyh(l,r);
            bool ff=1;
            for(int i=0;i<20;i++)
            {
                cout<<yh[i]<<' '<<bk[i]<<'\n';
                if(yh[i]!=bk[i])
                {
                    ff=0;
                }
            }
            if(ff)
            {
                ans++;
            }
            cout<<ff<<'\n';
        }
        l++;
    }
    cout<<ans;
    return 0;
}
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3
*/
