#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[100005],t[100005];
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    for(int i=1;i<=q;i++){
        string a,b;
        cin>>a>>b;
        int cnt=0;
        for(int j=1;j<=n;j++){
                int xb=a.find(s[j]);
            if(xb!=string::npos&&b.find(t[j])!=string::npos){
                string tem=a;
                a.erase(xb,s[j].size());
                a.insert(xb,t[j]);
                //cout<<xb<<' '<<a<<' '<<b<<' '<<s[j]<<' '<t[jendl;
                if(a==b)cnt++;
                a=tem;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
