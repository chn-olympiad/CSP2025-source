#include<bits/stdc++.h>
using namespace std;
struct seat
{
    int s,id;
};
seat s[105];
bool cmp(seat x,seat y)
{
    return x.s>y.s;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int l=n*m;
    for(int i=1;i<=l;i++)
    {
        cin>>s[i].s;
        s[i].id=i;
    }
    sort(s+1,s+l+1,cmp);
    int c=0,r=0,p=0;
    for(int i=1;i<=m;i++)
    {
        c++;
        for(int j=1;j<=n;j++)
        {
            if(i%2==1)r++;
            else r--;
            p++;
            if(s[p].id==1)
            {
                cout<<c<<" "<<r;
                return 0;
            }
        }
        if(i%2==1)r++;
        else r--;
    }
}
