#include<bits/stdc++.h>
#define N 200010
#define ll long long
using namespace std;
int n,q;
string s1[N],s2[N];
string s3[N],s4[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    for(int i=1;i<=q;i++) cin>>s3[i]>>s4[i];
    for(int i=1;i<=q;i++)
    {
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            int f=s3[i].find(s1[i]);
            if(f!=-1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
