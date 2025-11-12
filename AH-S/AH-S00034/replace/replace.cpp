#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,t,ans;
string s1[200005],s2[200005],t1,t2,tmp;
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    while(t--){
        cin>>t1>>t2;
        for(int i=1;i<=n;i++){
            int ls=s1[i].size(),lt=t1.size();
            for(int j=0;j+ls-1<lt;j++){
                tmp=t1;
                bool flag=true;
                for(int k=j;k<j+ls;k++){
                    if(tmp[k]!=s1[i][k-j]){
                        flag=false;
                        break;
                    }
                    tmp[k]=s2[i][k-j];
                }
                if(tmp==t2&&flag){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
