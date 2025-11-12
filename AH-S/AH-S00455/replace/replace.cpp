#include<bits/stdc++.h>
using namespace std;
string a[200005],s,b[200005],t;
int n,q;
char iu;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=q;i++){
        cin>>s>>t;
        bool ok=0;
        long long cnt=0;
        for(int j=2;j<s.size();j++){
            if(s[j]!=s[j-1]&&s[j-1]!=s[j-2]&&s[j-2]!=s[j]){
                ok=1;
            }
            if(s[j]!=s[j-1]&&s[j-1]!=s[j-2]){
                iu=s[j-1];
            }
        }
        if(ok==0){
            int iq=s.find(iu)-t.find(iu);
            for(int j=1;j<=n;j++){
                int o=s.find(a[j]);
                if(o!=-1){
                    if(iq==a[j].find(iu)-b[j].find(iu)){
                            cnt++;
                    }
                }
            }
        }else{
            for(int j=1;j<=n;j++){
                int o=s.find(a[j]);
                if(o!=-1){
                    string k=s.substr(0,o)+b[j]+s.substr(o+a[j].size(),s.size()-o-a[j].size());
                    if(k==t){
                        cnt++;
                    }
                }
            }
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
