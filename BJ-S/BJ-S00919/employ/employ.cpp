#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=1,sum2,num=1,q=998244353,u,k;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=m;i++)
    {
        cin>>u;
        if(u==0) k++;
    }
    m-=k;
    n-=k;
    for(int i=m;i<=n;i++)
    {
        sum=1;
        num=1;
        for(int j=1;j<=m;j++)
        {
            sum=sum*(n-j+1)/(j);
        }
        sum2+=sum;
        sum2=sum2%q;
    }
    cout<<sum2;
}