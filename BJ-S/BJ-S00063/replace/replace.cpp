#include <iostream>
using namespace std;
pair <string,string> change[1003];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>change[i].first>>change[i].second;
    }
    while(q--){
        string t1,t2;
        string t;
        cin>>t1>>t2;
        long long ans=0;
        int stt_w;
        for(int i=0;i<t1.length();i++){
            if(t1[i]!=t2[i]) {stt_w=i; break;}
        }
        for(int i=1;i<=n;i++){
            for(int stt=max(0,stt_w-(int)change[i].first.length()+1);stt<=stt_w;stt++){
                t=t1;
                for(int c=stt;c<=stt+(int)change[i].first.length()-1;c++) t[c]=change[i].second[c-stt];
                bool f=1;
                for(int c=0;c<=t.length();c++) {if(t[c]!=t2[c]){f=0;}}
                if(f) ans++;
            }

        }
        cout<<ans;
    }
}

