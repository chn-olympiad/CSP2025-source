#include<bits/stdc++.h>
using namespace std;
map<string,string>  a;
int n,q;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string x,y;
        cin>>x>>y;
        a[x]=y;
    }
    while(q--){
            int ans=0;
        string t1,t2;
        cin>>t1>>t2;
        for(int i=0;i<t1.size();i++){
            for(int len=1;len+i-1<t1.size();len++){
                string now=t1.substr(i,len),to=t1.substr(0,i);
                if(a.find(now)!=a.end()){
                    to+=a[now];
                    to+=t1.substr(i+len,t1.size()-i-len);
                    if(t2==to){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
