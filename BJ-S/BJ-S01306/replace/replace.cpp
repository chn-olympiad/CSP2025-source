#include <bits/stdc++.h>
using namespace std;
int ans=0;
string s[200005][3];
string t1,t2;
int n,q;

string change(string &a,int pos,string b){
    string str=a;
    for(int i=pos;i<b.size()+pos&&i<a.size();i++){
        str[i]=b[i];
    }
    return str;
}

void Dfs(string a,int x){
    cout<<a<<endl;
    if(a==t2){
        ans++;
        return ;
    }
    for(int i=x;i<t1.size();i++){
        string sum;
        for(int j=i;j<t2.size();j++){
            sum+=a[j];
            for(int k=1;k<=n;k++){
                if(sum==s[k][1]){
                    Dfs(change(a,i,s[k][2]),j+1);
                }
            }
        }
    }
}


int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s[i][1]>>s[i][2];
    }
    /*for(int i=1;i<=n;i++){
        cout<<s[i][1]<<" "<<s[i][2]<<endl;
    }*/
    for(int i=1;i<=q;i++){
        cin>>t1>>t2;
        ans=0;
        Dfs(t1,0);
        t1.clear();
        t2.clear();
        cout<<ans<<endl;
    }
    return 0;
}
