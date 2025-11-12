#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,q;
string s[N][2];
int read()
{
    int k=0,f=1;
    char c=getchar();
    while(c<'0' || c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0' && c<='9'){
        k=k*10+c-'0';
        c=getchar();
    }
    return k*f;
}
string t1,t2;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>s[i][0]>>s[i][1];
    if(n<=100&&q<=100){
         while(q--){
            cin>>t1>>t2;
            int ans=0;
            for(int i=1;i<=n;++i){
                int len0=s[i][0].size(),len1=s[i][0].size();
                int len=t1.size();
                int tmp=t1.find(s[i][0]);
                if(tmp!=-1){
                    string tt="";
                    for(int j=0;j<tmp;++j) tt+=t1[j];
                    tt+=s[i][1];
                    for(int j=tmp+len0;j<len;++j) tt+=t1[j];
                    // cout<<"i="<<i<<" tt="<<tt<<"\n";
                    if(tt==t2){
                        ++ans;
                    }
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    while(q--) cout<<0<<"\n";
    return 0;
}