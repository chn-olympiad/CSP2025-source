#include <bits/stdc++.h>
using namespace std;
#define int long long
string s[200005][2];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n;++i)
    {
        cin>>s[i][0]>>s[i][1];
    }
    while(q--)
    {
        string t1,t2;
        cin>>t1>>t2;
        int len1=t1.size();
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
            int len2=s[i][0].size();
            for(int j=0;j<len1;++j)
            {
                if(len2>len1-j)
                {
                    break;
                }
                if(t1.substr(j,len2)==s[i][0]&&t1.substr(0,j)+s[i][1]+t1.substr(j+len2,len1-j)==t2)
                {
                    ++cnt;
                }
            }
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
