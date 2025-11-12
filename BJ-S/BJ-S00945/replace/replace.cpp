#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
string s1 [N],s2[N];
string t1,t2;
int a1[N], a2[N];
map<int,vector<pair<int,int> > >mp;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    int ss=0;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        ss+=s1[i].size()*2;
    }
    if(ss<=3000){
        for(int j=1;j<=q;j++){
            int ans=0;
            cin>>t1>>t2;
            if(t1.length()!=t2.length()){
                cout<<0<<endl;
                continue;
            }
            for(int j=0;j<=(int)t1.length();j++){
                for(int k=1;k<=n;k++){
                    int fl=0;
                    for(int p=0;p<t1.length();p++){
                        if(p<j||p>=j+s1[k].length()){
                            if(t1[p]!=t2[p]){
                                fl=1;
                                break;
                            }
                        }else{
                            if(s1[k][p-j]!=t1[p]||s2[k][p-j]!=t2[p]){
                                fl=1;
                                break;
                            }
                        }
                    }
                    if(fl==0){
                        ans++;
                    }
                }
            }
            cout<<ans<<endl;
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<s1[i].size();j++){
            if(s1[i][j]=='b'){
                a1[i]=j;
            }
        }
        for(int j=0;j<s2[i].size();j++){
            if(s2[i][j]=='b'){
                a2[i]=j;
            }
        }
        mp[a1[i]-a2[i]].push_back(make_pair(a1[i],s1[i].size()));
    }
    for(int j=1;j<=q;j++){
        int ans=0;
        cin>>t1>>t2;
        if(t1.length()!=t2.length()){
            cout<<0<<endl;
            continue;
        }
        int b1,b2;
        for(int j=0;j<t1.size();j++){
            if(t1[j]=='b'){
                b1=j;
            }
        }
        for(int j=0;j<t2.size();j++){
            if(t2[j]=='b'){
                b2=j;
            }
        }
        for(auto k : mp[b1-b2]){
            if(b1>=k.first&&t1.size()-b1>=k.second-k.first){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
