#include<bits/stdc++.h>
using namespace std;
int s[110];
bool cmp(int x,int y)
{
    return x>y;

}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int c,r;
    int mark=0;
    int len=0;
    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=m;j++)
        {
            cin>>s[i];
            mark=s[1];
        }
    }
    sort(s+1,s+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(mark==s[i])
        {
            int len=i;
        }

    }
    return 0;
}
