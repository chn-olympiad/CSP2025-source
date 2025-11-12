#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
int a[5005];
void dfs(int l,int now,int maxn)
{
    for(int i=l;i<maxn;i++)
    {
        if(a[i]==0) continue;
        int aa=a[i];
        a[i]=0;
        now+=aa;
        if(now>a[maxn])
        {
            cnt++;
            cnt%=998244353;
            /*
            for(int j=0;j<n;j++)
            {
                if(a[j]==0) cout<<j+1<<" ";
            }
            cout<<endl;
            */
        }
        dfs(i+1,now,maxn);
        now-=aa;
        a[i]=aa;
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int maxn=n-1;maxn>=0;maxn--)
    {
        dfs(0,0,maxn);
    }
    cout<<cnt<<endl;
    return 0;
}
