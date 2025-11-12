#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
const int M=5e6+5;
bool h[M];
string a,b,f,now;
int n,q,ans,l;
map<string,string>mp;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        mp[a]=b;
        h[a.size()]=1;
    }
    while(q--){
        cin>>a>>b;
        ans=0;
        l=a.size();
        for(int i=0;i<l;i++){
            now="";
            for(int j=i;j<l;j++){
                now+=a[j];
                if(!h[j-i+1]) continue;
                if(!mp.count(now)) continue;
                f="";
                for(int k=0;k<l;k++){
                    if(k==i){
                        f+=mp[now];
                        k=j;
                        continue;
                    }
                    f+=a[k];
                }
                if(f==b) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
