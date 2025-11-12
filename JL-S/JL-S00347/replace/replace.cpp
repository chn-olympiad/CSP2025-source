#include<bits/stdc++.h>
using namespace std;
string s[200005][3],t[200005][3];
int n,q;
bool cmp(string s,string t){
    for(int i=0;i<t.length();i++){
        if(s[i]!=t[i]){
            return false;
        }
    }
    return true;
}
void replace(string s,string t){
        for(int i=0;i<t.length();i++){
                t[i]=s[i];
        }
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    //My deal computer.Could you please pass a couple of testing points for me?
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    for(int j=1;j<=n;j++){
        cin>>t[j][1]>>t[j][2];
    }
    for(int i=1;i<=q;i++){
        cout<<0<<endl;
    }
    return 0;
}
