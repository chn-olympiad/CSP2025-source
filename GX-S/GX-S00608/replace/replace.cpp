#include<bits/stdc++.h>
using namespace std;
int n,q;
long long ans;
string s,t,s1,t1;
map<pair<string,string>,int> w;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s>>t;
        w[{s,t}]++;
    }
    while(q--){
        cin>>s>>t;
        if((int)s.size()!=(int)t.size()){
            puts("0");
            continue;
        }
        ans=0;
        int x=0,y=0,n=(int)s.size();
        for(int i=1;i<=n;i++){
            if(s[i-1]==t[i-1]) x++;
            else{
                break;
            }
        }
        for(int i=n;i>0;i--){
            if(s[i-1]==t[i-1]) y++;
            else{
                break;
            }
        }
        for(int i=1;i<=x+1;i++){
            s1="";
            t1="";
            for(int j=i;j<=n-y;j++)
                s1+=s[j-1],t1+=t[j-1];
            for(int j=n-y;j<=n;j++){
                if(w.count({s1,t1}))
                    ans+=w[{s1,t1}];
                if(j!=n){
                    s1+=s[j];
                    t1+=t[j];
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
