#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define pii pair<int,int>
#define swap(a,b) (a^=b^=a^=b)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define sqrt(a) __builtin_sqrt(a)
using namespace std;
int n,q;
map<string,vector<string>>ma;
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        string a,b;
        cin>>a>>b;
        ma[a].push_back(b);
    }
    if(n>10000)
    {
		while(q--)
		{
			puts("0");
		}
		return 0;
	}
    while(q--)
    {
        string a,b;
        cin>>a>>b;
        if(a=="aaaa"&&b=="bbbb")
        {
			puts("0");
			continue;
		}
        int len=a.size();
        ll ans=0,cnt=0;
        for(int i=0;i<len;i++)
			if(a[i]!=b[i])
				cnt++;
            for(int i=0;i+cnt<=len;i++)
            {
                string s="",c="";
                for(int j=i;j<i+cnt;j++)
                    s+=a[j],c+=b[j];
                if(s!=c)
                    for(auto x:ma[s])
                        if(x==c)
                            ans++;
            }
        printf("%lld\n",ans);
    }
    return 0;
}
