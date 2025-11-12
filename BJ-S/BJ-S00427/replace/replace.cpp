#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b,int ii){
    int lenb=b.size();
    for(int i=0;i<lenb;i++){
        if(a[ii+i]!=b[i]){
            return false;
        }
    }
    return true;
}
string change(string a,string b,int ii){
    int lena=a.size(),lenb=b.size();
    for(int i=0;i<lenb;i++){
        a[ii+i]=b[i];
    }
    return a;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s[2][100005];
    for(int i=1;i<=n;i++){
        cin>>s[0][i]>>s[1][i];
    }
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        int ans=0;
        for(int i=1;i<=n;i++){
            int len=t1.size();
            for(int j=0;j<len;j++){
                if(check(t1,s[0][i],j)){
                    if(change(t1,s[1][i],j)==t2){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}