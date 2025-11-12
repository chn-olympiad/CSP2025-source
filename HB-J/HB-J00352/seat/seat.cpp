#include<bits/stdc++.h>
using namespace std;
int n,m,mp[15][15],k,num[105],pl,j,i;
bool flag=false,flag1=false;
void mv()
{
    while(j<=n)
    {
        if(!flag)
        {
            for(;i<=n;i++)
            {
                mp[i][j]=num[k--];
            }
            i--;
        }
        if(flag)
        {
            for(;i>=1;i--)
            {
                mp[i][j]=num[k--];
            }
            i++;
        }
        j++;
        if(j%2==0) flag=true;
        else flag=false;
    }
    return;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    k=n*m;
    for(int i=1;i<=k;i++)
    {
        cin>>num[i];
        if(i==1) pl=num[i];
    }
    sort(num+1,num+k+1);
    j=1,i=1;
    mv();
    if(flag1) return 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(mp[i][j]==pl)
            {
               cout<<j<<" "<<i;
               return 0;
           }
        }
    }
    return 0;
}
