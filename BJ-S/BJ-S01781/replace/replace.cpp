#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
    string a,b;
}a[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
    }
    while(q--){
        string s,t;
        cin>>s>>t;
        if(s.size()!=t.size()){
            cout<<"0\n";
            continue;
        }
        if(s==t){
            cout<<"0\n";
            continue;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(s.find(a[i].a)<s.size()){
                int j=s.find(a[i].a);
                int k=s.find(a[i].a)+a[i].a.size();
                string f=s.substr(0,j);
                f+=a[i].b;
                f+=s.substr(k,s.size()-k);
                if(f==t) ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
