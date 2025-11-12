#include<bits/stdc++.h>
using namespace std;
long long n,q;
string s[200010],t[200010];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(long long i=1;i<=n;i++){
        cin>>s[i]>>t[i];
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        long long ans=0;
        for(long long i=1;i<=n;i++){
            for(long long j=0;j<a.size();j++){
                if(a[j]==s[i][0]){
                    string asdf=a;
                    bool flag=1;
                    for(long long k=0;k<s[i].size();k++){
                        if(j+k>a.size()){
                            a=asdf;
                            flag=0;
                            break;
                        }
                        if(a[j+k]!=s[i][k]) flag=0;
                    }
                    if(flag){
                        //cout<<"!!!!\n";
                        for(long long k=0;k<s[i].size();k++){
                            if(j+k>a.size()){
                                a=asdf;
                                break;
                            }
                            a[j+k]=t[i][k];
                        }
                    }
                    if(a==b){
                        ans++;
                        a=asdf;
                    }else{
                        a=asdf;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
// hat???
// i'm so noob
// pls 20pts and more
// i don't like T3 and csp-s
// i can't do it
// T_T
// tot pts:20/0+20+40+8=68/88
// shit ,what a suck code
// O(n*l1*l1)
// pls rp++

