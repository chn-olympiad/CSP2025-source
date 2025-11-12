#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[1001];
int b[10001];
signed main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
        t[b[i]]=i;
    }
    sort(b+1,b+n*m+1);
    int o;
    for(int i=n*m;i>=1;i--)
    {
        if(t[b[i]]==1)
        {
            o=n*m-i;
            break;
        }
    }
    int y=o/n;
    int x=o%n+1;
    if(y%2==1)
    {
        x=n-x+1;
    }
    cout<<y+1<<" "<<x;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
