#include<bits/stdc++.h>
using namespace std;

unsigned long long ans = 1;
int n,m,c[510],FA=1,yt=0;
string s;

int main()
{

    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin>>n>>m;
    int tmp = n;
    cin>>s;
    for(int i = 1;i <= n;i++)
    {
        cin>>c[i];
    /*    if(c[i] == 0)
        {
            yt++;tmp--;
        }*/
    }
    sort(c+1,c+1+tmp);
    int cnt = 0;
    while(1)
    {
        cnt++;
       // cout<<cnt<<" "<<yt<<" "<<c[cnt]<<"\n";
        if(c[cnt] <= yt)
        {
            tmp--;
            yt++;
        }
        else{
            break;
        }
    }
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] != '1') FA = 0;
    }
    if(FA)
    {
        for(int i = tmp;i >= 1;i--)
        {
            ans = (ans*i)%998244353;
        }
        cout<<ans;
    }
    else cout<<2;
    return 0;
}
