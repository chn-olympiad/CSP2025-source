#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1005];
map<pair<int,int>,int>m;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=1;j<=i;j++)
        {
            m[{j,i}]=m[{j,i-1}]^a[i];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            if(m[{j,j+i-1}]==k)
            {
                ans++;
                for(int k=j;k<=n;k++)
                {
                    for(int l=1;l<=j;l++)
                    {
                        m[{l,k}]=-1;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
//happy halloween!
//I'm Kremlin897! luogu:1046158
