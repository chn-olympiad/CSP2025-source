#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n,q;
long long ans;
string s[N][2];
map<pair<string,string>,int> mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
        mp[make_pair(s[i][0],s[i][1])]++;
    }
    for(int i=1;i<=q;i++){
        string c,t;
        ans=0ll;
        cin>>c>>t;
        int len=c.size(),len2=t.size();
        if(len!=len2){
            cout<<0<<endl;
            continue;
        }
        int tmp=-1,tmp2=-1;
        for(int j=0;j<len;j++){
            if(c[j]!=t[j]){
                if(tmp==-1) tmp=j;
                tmp2=j;
            }
        }
        for(int j=0;j<=tmp;j++){
            for(int k=tmp2;k<len;k++){
                string f=c.substr(j,k-j+1),p=t.substr(j,k-j+1);
                ans=ans+(long long)mp[make_pair(f,p)];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
