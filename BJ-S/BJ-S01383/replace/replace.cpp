#include<bits/stdc++.h>
using namespace std;
int n,q;
string s[100005][2],x,y;
bool find(string s1,string s2){
    for(int i=0;i<s1.size()-s2.size();i++){
            bool b=1;
        for(int j=0;j<s2.size();j++){
            if(s1[i+j]!=s2[j]){
                b=0;
            }
        }
        if(b)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][0]>>s[i][1];
    }
    for(int k=1;k<=q;k++){
        cin>>x>>y;
        if(x.size()!=y.size()){
            cout<<0<<endl;
            continue;
        }
        string delta,de;
        int h=0,t=1;
        for(int i=0;i<x.size();i++){
            if(x[i]!=y[i]){
                t=i;
            }
            if(x[x.size()-i-1]!=y[x.size()-i-1]){
                h=x.size()-i-1;
            }
        }
        for(int i=h;i<=t;i++){
            delta=delta+y[i];
            de=de+x[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(delta.size()>s[i][1].size()){
                    continue;
            }
            if(s[i][0]==de&&s[i][1]==delta){
                ans++;
                continue;
            }


                for(int j=0;j<s[i][0].size()-delta.size();j++){
                    bool b=1;
                    for(int l=0;l<delta.size();l++){
                        if(delta[l]!=s[i][1][l+j]||de[l]!=s[i][0][l+j]){b=0;
                        }
                    }
                    if(b) {ans++;break;}
                }

        }
        cout<<ans<<endl;
    }
}
