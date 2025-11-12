#include <bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005];
int c[10005];
int d[10005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;cin>>s1>>s2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b'){
                a[i]=j;
            }
        }
        for(int j=0;j<s2.size();j++){
            if(s2[j]=='b'){
                b[i]=j;
            }
        }
        c[i]=s1.size()-a[i];d[i]=s2.size()-b[i];
    }
    for(int i=1;i<=q;i++){
        string s1,s2;cin>>s1>>s2;
        int cnt1,cnt2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b'){
                cnt1=j;
            }
        }
        for(int j=0;j<s2.size();j++){
            if(s2[j]=='b'){
                cnt2=j;
            }
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            if(a[j]<=cnt1 && b[j]<=cnt2 && c[i]<=s1.size()-cnt1 && d[i]<=s2.size()-cnt2){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
