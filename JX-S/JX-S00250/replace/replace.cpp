#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
int c1[N],c2[N],ct1,ct2;
string s1[N],s2[N];
string t1,t2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        int len=s1[i].size();
        for(int j=0;j<len;j++){
            if(s1[i][j]=='b') c1[i]=j;
            if(s2[i][j]=='b') c2[i]=j;
        }
    }
    while(q--){
        cin>>t1>>t2;
        ct1=ct2=0;
        int len=t1.size();
        for(int i=0;i<len;i++){
            if(t1[i]=='b') ct1=i;
            if(t2[i]=='b') ct2=i;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if((c1[i]-c2[i])==(ct1-ct2))
                ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
