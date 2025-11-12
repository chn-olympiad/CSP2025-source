#include<bits/stdc++.h>
#define int long long
#define F(i,n,m) for(int i=n;i<=m;i++)
#define f(i,n,m) for(int i=n;i<m;i++)
#define FF(i,n,m) for(int i=n;i>=m;i--)
#define ff(i,n,m) for(int i=n,i>=m;i--)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
using namespace std;
string s,ans;
bool cmp(char a,char b){
    return a>b;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    int n=s.size();
    f(i,0,n)
        if(s[i]>='0'&&s[i]<='9')
            ans+=s[i];
    sort(ans.begin(),ans.end(),cmp);
    if(ans[0]==0) puts("0");
    else cout<<ans;
    return 0;
}