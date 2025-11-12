#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
long long ans;
string s1,s2;
map<string,string>mp;
bool check(int l,int r){
    string a=mp[s1.substr(l,r)],b=s2.substr(l,r);
    //cout<<a.size()<<a<<" "<<b<<endl;
    if(mp[s1.substr(l,r)].size()!=b.size())return 0;

    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])return 0;
    }
    return 1;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1>>s2;
        mp[s1]=s2;
    }
    while(q--){
        ans=0;
        cin>>s1>>s2;
        int l=10000000,r=-1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])l=min(l,i),r=max(r,i);
        }
        //cout<<l<<" "<<r<<endl;
        for(int i=0;i<s1.size();i++){
            for(int j=1;i+j<=s1.size();j++){
                //if(i==2&&j==2)cout<<"////////////"<<endl;
                //cout<<"ii"<<s1.substr(2,2)<<"ii\n";
                if(i<=l&&i+j>r&&check(i,j)==1){
                    ans++;
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
