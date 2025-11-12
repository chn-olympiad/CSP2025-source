/*
CSP-J 2025 T2
Author: DFLJ
AC Time: 09:16
*/
#include<bits/stdc++.h>
using namespace std;
int s[1001];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,k,w,r;
    cin>>n>>m;
    k=n*m;
    for(int i=1; i<=n*m; i++)
    {
        cin>>s[i];
    }
    r=s[1];
    sort(s+1,s+k+1);
    reverse(s+1,s+k+1);
    for(int i=1; i<=k; i++)
    {
        if(s[i]==r)
        {
            w=i;
            break;
        }
    }
    int cnt=0;
    for(int i=1; i<=m; i++)
    {
        if(i&1)
        {
            for(int j=1; j<=n; j++)
            {
                cnt++;
                if(cnt==w)
                {
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=n; j>=1; j--)
            {
                cnt++;
                if(cnt==w)
                {
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}