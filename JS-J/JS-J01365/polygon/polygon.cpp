#include <bits/stdc++.h>
using namespace std;
int n,maxn,total,cnt;
int l[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
        total+=l[i];
        maxn=max(l[i],maxn);
    }
    if(n<=2) cout<<cnt;
    else{
        if(total>2*maxn) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
