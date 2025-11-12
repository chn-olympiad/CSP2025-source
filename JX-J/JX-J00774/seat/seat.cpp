#include<bits/stdc++.h>
using namespace std;
struct si
{
    int a;
    int b;
}s[111];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b[11][11],k,o,l=1;
    cin>>n>>m;
    s[0].a=0;
    for(int i=1;i<=m*n;i++)
    {
        cin>>s[i].a;
        s[i].b=l;
        l++;
        if(s[i].a>s[i-1].a&&(i-1)!=0){k=s[i].a;o=s[i].b;s[i].a=s[i-1].a;s[i].b=s[i-1].b;s[i-1].a=k;s[i-1].b=o;}
    }
    k=1;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
            for(int j=1;j<=n;j++)
            {
                if(s[k].b==1) {cout<<i<<' '<<j;return 0;}
                else k++;
            }
        else
            for(int j=n;j>=1;j--)
            {
                if(s[k].b==1) {cout<<i<<' '<<j;return 0;}
                else k++;
            }
    }
    return 0;
}
