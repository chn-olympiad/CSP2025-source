#include <bits/stdc++.h>
using namespace std;
long long n,q;
string s1[200005],s2[200005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(long long i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    while(q--)
    {
        long long ans=0;
        string t1,t2;
        cin>>t1>>t2;
        string t3=t1;
        for(long long i=1;i<=n;i++)
        {
            long long st=0;
            while(t1.find(s1[i],st)!=string::npos)
            {
                st=t1.find(s1[i],st);
                t1.replace(st,s1[i].size(),s2[i]);
                if(t1==t2) ans++;
                t1=t3;
                st++;
            }
        }
        cout<<ans;
        if(q!=0) cout<<endl;
    }
    return 0;
}
