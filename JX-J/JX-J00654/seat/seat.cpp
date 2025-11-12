#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,sum=1,na=1,j=1;
struct node{
    int pr,ii;
}a[105];
bool cmp(node x,node y)
{
    return x.pr>y.pr;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i].pr;
        a[i].ii=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++)
    {
        if (a[i].ii==1)
        {
            break;
        }
        if (ans==n && j==1)
        {
            sum++;
            j=2;
            continue;
        }
        else if (ans==1 && j==2)
        {
            sum++;
            j=1;
            continue;
        }
        if (j==1) ans++;
        else if (j==2) ans--;
    }
    cout<<sum<<' '<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
