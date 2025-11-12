#include<bits/stdc++.h>
using namespace std;
int compare(string s1,string s2,int l,int r,int s){
    for(int i = l;i<=r;i++){
        if(s1[i] != s2[s]){
            return false;
        }
        s++;
    }return true;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    string s1[100010] = {};
    string s2[100010] = {};
    for(int i = 1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i = 1;i<=q;i++){
        string t1,t2;
        cin>>t1>>t2;
        int ans = 0;
        for(int j = 1;j<=n;j++){
            for(int z = 0;z+s1[j].size()<=t1.size();z++){
                if(compare(t1,t2,0,z-1,0) && compare(t1,t2,z+s1[j].size(),t1.size()-1,z+s1[j].size())){
                    if(compare(t1,s1[j],z,z+s1[j].size()-1,0) && compare(t2,s2[j],z,z+s1[j].size()-1,0)){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
