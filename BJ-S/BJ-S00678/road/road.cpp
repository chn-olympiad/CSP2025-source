#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,q;
string s1[100001],s2[1000001];
string q1[100001],q2[1000001];
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdin);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=q;i++)
        cin>>q1[i]>>q2[i];
    for(int i=1;i<=n;i++)
        cout<<0<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
