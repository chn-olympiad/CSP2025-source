#include<bits/stdc++.h>
using namespace std;
int s[100000];
int main()
{
    freopen("polygon.in","r",stdin);
    1 freopen("polygon.out","w",stdout);
    int m,a=0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=m-2;i++)
    {
        int t=s[i];
        for(int y=i+1;y<=m-1;y++)
        {
            for(int j=y;j<=m-1;j++)
            {
                for(int x=j+1;x<=m;j++)
                {
                    if(t+s[j]<s[x])
                    {
                        break;
                    }
                    else
                    {
                        a+=1;
                    }
                }
            }
            t+=s[y];
        }
    }
    cout<<a;
    return 0;
}
