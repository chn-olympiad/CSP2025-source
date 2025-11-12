#include<bits/stdc++.h>
using namespace std;
int a[510],b[510],c[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        int h=c-'0';
        a[i]=h;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        c[i]=i;
    }
    int ans=0;
    do
    {
        int h=0,num=0,id=1;
        for(int i=1; i<=n; i++)
        {
            if(a[id]==0)
            {
                num++;
                id++;
            }
            else if(b[c[i]]<=num)
            {
                num++;
                id++;
            }
            else
            {
                h++;
                id++;
            }
        }
        if(h>=m)
        {
            ans++;
        }
    }while(next_permutation(c+1,c+n+1));
    cout<<ans%998244353<<endl;
}
