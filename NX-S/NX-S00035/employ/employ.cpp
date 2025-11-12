#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);

    int n,m;
    long long re;
    string s;
    cin>>n>>m;
    cin>>s;
    int ys[501];
    for(int i=1;i<=n;i++)
    {
        cin>>ys[i];
    }
    if(m==n)
    {
        re=1;
        for(int i=1;i<=n;i++)
        {
            re=re*i;
        }
        cout<<re;
    }
    return 0;
}
