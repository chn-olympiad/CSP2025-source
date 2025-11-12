#include <bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n,q,ans;
string a[N],b[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    while(q--){
        ans=0;
        string t1,t2;
        cin>>t1>>t2;
        if(t1.size()!=t2.size()) cout<<0<<'\n';
        for(int i=0;i<t1.size();i++){
            for(int k=1;k<=t1.size()-i;k++){
                string tmp1=t1.substr(i,k);
                //cout<<tmp1<<' ';
                for(int j=1;j<=n;j++){
                    if(tmp1==a[j]){
                        string tmp2=t1.substr(0,i)+b[j]+t1.substr(i+k);
                        //cout<<tmp2<<'\n';
                        if(tmp2==t2) ans++;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

