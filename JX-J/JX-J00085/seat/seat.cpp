#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[150];
int o=1;
int ansn,ansm;
bool bol=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int k=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                if(b[o]==k)
                {
                    ansn=i;
                    ansm=j;
                    bol=1;
                    break;
                }
                o++;
            }
        }
        else if(i%2==0)
        {
            for(int j=m;j>=1;j--)
            {
                if(b[o]==k)
                {
                    ansn=i;
                    ansm=j;
                    bol=1;
                    break;
                }
                o++;
            }
        }
        if(bol==1)
        {
            break;
        }
    }
    cout<<ansn<<" "<<ansm;
    return 0;
}
