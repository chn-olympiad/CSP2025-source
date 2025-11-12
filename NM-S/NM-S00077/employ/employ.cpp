#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,linshi,shuzi=0;
    string st;
    cin>>n>>m;
    cin>>st;
    for(int i=0;i<n;i++)
    {
        cin>>linshi;
        if(linshi==0)
        {
            shuzi++;
        }
    }
    long long int ji=1;
    for(int i=1;i<=n;i++)
    {
        ji*=i;
        ji%=998244353;
    }

    cout<<ji%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
