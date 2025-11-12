#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q;
string s,v;
map<pair<string,string>,int> mp;
long match(long long l,long long r){
    return mp[make_pair(s.substr(l,r-l+1),v.substr(l,r-l+1))];
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s>>v;
        mp[make_pair(s,v)]+=1;
    }
    for(int i=1;i<=q;i++){

        cin>>s>>v;
        int lens=s.length();
        int lenv=v.length();
        long long ans=0;
        if(lens!=lenv)ans=0;
        else{
            int first,last;
            for(int i=0;i<lens;i++){
                if(s[i]!=v[i]){
                    first=i;
                    break;
                }
            }
            for(int i=lens-1;i>=0;i--){
                if(s[i]!=v[i]){
                    last=i;
                    break;
                }
            }
            for(int i=0;i<=first;i++){
                for(int j=last;j<lens;j++){
                    ans+=match(i,j);
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;

}
