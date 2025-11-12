#include<bits/stdc++.h>
using namespace std;
int n,q;
string s1[200005],s2[200005],t1[200005],t2[200005];
map<string,int> m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        int t=0;
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]==s2[i][j]){
                t++;
            }else{
                break;
            }
        }
        s1[i].erase(0,t);
        s2[i].erase(0,t);
        t=0;
        for(int j=s1[i].size()-1;j>=0;j--){
            if(s1[i][j]==s2[i][j]){
                t++;
            }else{
                break;
            }
        }
        s1[i].erase(s1[i].size()-t,t);
        s2[i].erase(s2[i].size()-t,t);
        string s=s1[i]+" "+s2[i];
        m[s]++;
    }
    for(int i=1;i<=q;i++){
        cin>>t1[i]>>t2[i];
        if(t1[i].size()!=t2[i].size()){
            cout<<0<<endl;
            continue;
        }
        int t=0;
        for(int j=0;j<t1[i].size();j++){
            if(t1[i][j]==t2[i][j]){
                t++;
            }else{
                break;
            }
        }
        t1[i].erase(0,t);
        t2[i].erase(0,t);
        t=0;
        for(int j=t1[i].size()-1;j>=0;j--){
            if(t1[i][j]==t2[i][j]){
                t++;
            }else{
                break;
            }
        }
        t1[i].erase(t1[i].size()-t,t);
        t2[i].erase(t2[i].size()-t,t);
        string s=t1[i]+" "+t2[i];
        cout<<m[s]<<endl;
    }
    return 0;
}
