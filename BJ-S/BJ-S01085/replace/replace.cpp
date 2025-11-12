#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s[N][2];
void solve(){
    string t[2];
    cin>>t[0]>>t[1];
    if(t[0].size()!=t[1].size()){
        cout<<"0\n";
        return;
    }
    if(n>2000){
        int len=t[0].size();
        int ans=0;
        int l[2],r[2];
        for(int i=0;i<len;i++){
            if(t[0][i]=='b'){
                l[0]=i;
                r[0]=len-i-1;
            }
        }
        for(int i=0;i<len;i++){
            if(t[1][i]=='b'){
                l[1]=i;
                r[1]=len-i-1;
            }
        }
        for(int i=1;i<=n;i++){
            int l1,l2,r1,r2;
            int g=s[i][0].size();
            for(int j=0;j<g;j++){
                if(s[i][0][j]=='b'){
                    l1=j;
                    r1=g-j-1;
                    break;
                }
            }
            for(int j=0;j<g;j++){
                if(s[i][1][j]=='b'){
                    l2=j;
                    r2=g-j-1;
                    break;
                }
            }
            if(l1-l2==l[0]-l[1]&&l1<=l[0]&&r1<=r[0]){
                ans++;
            }
        }
        cout<<ans<<"\n";
        return;
    }
    int len=t[0].size(),l,r;
    for(int i=0;i<len;i++){
        if(t[0][i]!=t[1][i]){
            l=i;
            break;
        }
    }
    for(int i=len-1;i>=0;i--){
        if(t[0][i]!=t[1][i]){
            r=i;
            break;
        }
    }
    int ans=0;
    for(int f=0;f<=l;f++){
        for(int e=r;e<len;e++){
            string d[2]={"",""};
            for(int i=f;i<=e;i++){
                d[0]+=t[0][i];
                d[1]+=t[1][i];
            }
            for(int i=1;i<=n;i++){
                if(d[0]==s[i][0]&&d[1]==s[i][1]){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    while(q--){
        solve();
    }
    return 0;
}
