#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s;
int c[505],num[505];
int main()
{
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        num[i]=s[i-1]-'0'+1;
    }
    do
    {
        int cnt=0,gets=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<num[i]<<" ";
            if(num[i]&&cnt<=c[i])
            {
                gets++;
            }
            else cnt++;
        }
        //cout<<endl;
        if(gets>=m) ans=(ans+1)%998244353;
    }
    while(next_permutation(num+1,num+n+1));
    cout<<ans;
    return 0;
}
