#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[200005];
unordered_map<string,string>mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string t;
        cin>>s[i]>>t;
        mp[s[i]]=t;
    }
    while(q--){
        string a,b;
        cin>>a>>b;
        int ans=0,len_a=a.size(),len_b=b.size();
        if(len_a!=len_b){
            cout<<ans<<endl;
            continue;
        }
        int pos=0;
        for(int i=0;i<len_a;i++){
            if(a[i]!=b[i]){
                pos=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(a.find(s[i])==string::npos||a.find(s[i])!=pos){
                continue;
            }
            int len=s[i].size();
            bool flag=true;
            for(int j=0;j<len;j++){
                if(mp[s[i]][j]!=b[pos+j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}