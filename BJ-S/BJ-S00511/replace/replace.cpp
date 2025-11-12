#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,M=1e6+5;
const ll mod=1e9+7,base=131;
string s[N][2];
int szs[N];
//ll hs[M],pw[M];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][0]>>s[i][1];
        szs[i]=s[i][0].size();
    }

    //for(i)
    for(int i=1;i<=q;i++)
    {
        string t1,t2;
        cin>>t1>>t2;
        int sz=t1.size();
        ll cnt=0;
        for(int i=1;i<=n;i++)
        {
            int pos=0;
            int res=t1.find(s[i][0],pos);
            while(res!=-1)
            {
                string x,z;
                if(res>0) x=t1.substr(0,res);
                else x="";
                if(res+szs[i]<=sz-1) z=t1.substr(res+szs[i]);
                else z="";
                string tmp=x+s[i][1]+z;
                if(tmp==t2)
                {
                    cnt++;
                }
                pos=res+1;
                res=t1.find(s[i][0],pos);
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
