#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,a[510],c[510],maxn=-1,mod=998244353;
    string s;
    cin>>n>>m>>s;
    for(int i=0;i<s.size();i++) a[i+1]=s[i]-48;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]>maxn) maxn=c[i];
    }
    cout<<maxn%mod<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
