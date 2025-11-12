#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[101];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>s[i];
    int g=s[1],h=0;;
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
        if(s[i]==g)
            h=i;
    for(int i=1;i<=m;)
    {
        for(int j=1;j<=n;j++)
        {
            if(h==1)
            {
                cout<<i<<" "<<j;
            }
            h--;
        }
        i++;
        for(int j=n;j>=1;j--)
        {
            if(h==1)
            {
                cout<<i<<" "<<j;
            }
            h--;
        }
        i++;
    }
    return 0;
}
