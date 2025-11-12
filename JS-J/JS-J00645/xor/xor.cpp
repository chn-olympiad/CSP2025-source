#include<bits/stdc++.h>
using namespace std;
int ans=0;
const int maxn=5e5+20;
int a[maxn];
bool x[25][maxn];
void turn2(int m)
{
    int i=1;
    do
    {
        if(a[m]%2==1)x[i][m]=1;
        a[m]/=2;
        i++;
    }while(a[m]);
}
bool check(int l,int r)
{
    if(l==1)
    {
        if(r==1)return false;
        else return true;
    }
    else
    {
        if(r==1)return true;
        else return false;
    }
}
bool solve(int l,int r)
{
    for(int i=l;i<r;i++)
    {
        for(int j=1;j<=25;j++)
        {
            if(check(x[j][i],x[j][i+1]))
            {
                x[j][i+1]=1;
            }
            else
            {
                x[j][i+1]=0;
            }
        }
    }
    for(int i=1;i<=25;i++)
    {
        if(x[i][r]!=x[i][0])return false;
    }
    return true;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    int k1=k;
    a[0]=k;
    turn2(0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k1)ans++;
        turn2(i);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(solve(i,j))
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
