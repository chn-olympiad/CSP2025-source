#include<bits/stdc++.h>
using namespace std;
/*

*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
typedef long long ll;
const int N=2e5+10;
int n,q,i,j,la,lb;
string s[N][3];
string a,b;
string rep(string a,int l,int r,string b)
{
    string t="";
    int i;
    for (i=0;i<l;i++) t+=a[i];
    t+=b;
    for (i=r+1;i<a.size();i++) t+=a[i];
    return t;
}
ll work(string a,string b)
{
    int i,j,la=a.size(),lb=b.size();
    ll res=0;
    for (i=1;i<=n;i++)
    {
        for (j=0;j<la-s[i][0].size()+1;j++)
        {
            if (a.substr(j,s[i][0].size())==s[i][0])
            {
                if (rep(a,j,j+s[i][0].size()-1,s[i][1])==b) res++;
            }
        }
    }
    return res;
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for (i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
    for (i=1;i<=q;i++)
    {
        cin>>a>>b;
        cout<<work(a,b)<<"\n";
    }
    return 0;
}