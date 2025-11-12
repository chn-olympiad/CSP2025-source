#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6*5;
int fin(string s,char c){
    for(int i=0;i<s.length();i++) if(s[i]=='b') return i;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,ans=0;
    cin>>n>>q;
    string s1[n+1],s2[n+1];
    int fr[n+1],ba[n+1],xg[n+1];
    string t[q+1],t2[q+1];
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        fr[i]=fin(s1[i],'b');
        ba[i]=s1[i].length()-fr[i]-1;
        xg[i]=fin(s2[i],'b')-fr[i];
    }
    for(int i=1;i<=q;i++){
        cin>>t[i]>>t2[i];
        int f=fin(t[i],'b'),b=t[i].length()-f-1,x=fin(t2[i],'b')-f;
        for(int j=1;j<=n;j++){
            if(f>=fr[j]&&b>=ba[j]&&xg[j]==x) {
                ans++;
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
