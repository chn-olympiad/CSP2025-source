#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        if(a.length()!=b.length()) {
            cout<<0<<'\n';
            continue;
        }
        int len=a.length();
        int st=-1,ed=0;
        for(int j=0;j<len;j++){
            if(a[j]!=b[j]){
                if(st==-1) st=j;
                ed=j;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int tmp=s1[i].find(a.substr(st,ed-st+1));
            if(tmp!=-1){
                int t2=b.find(s2[i]);
                if(t2==-1) continue;
                if(t2<=st&&t2+s2[i].length()-1>=ed){
                    ans++;
                }

            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}

