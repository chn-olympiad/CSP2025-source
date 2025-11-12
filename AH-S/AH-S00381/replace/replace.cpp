#include<bits/stdc++.h>
using namespace std;
bool zq(string a,string b){
    if(a.size()<b.size())swap(a,b);
    for(int i=0;i<=a.size()-b.size();i++){
        string pd="";
        for(int j=i;j<b.size()+i;j++)pd+=a[j];
        if(pd==b)return 1;
    }
    return 0;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,Q;
    cin>>n>>Q;
    string chu[n],mo[n];
    for(int i=0;i<n;i++)cin>>chu[i]>>mo[i];
    while(Q--){
        string s,t,zxfgg="",zzfgg="";
        cin>>s>>t;
        int ans=0,flag=0,sf[s.size()],left=0,right=s.size()-1;
        if(s.size()!=t.size()){
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                left=i;
                break;
            }
        }
        for(int i=s.size()-1;i>0;i--){
            if(s[i]!=t[i]){
                right=i;
                break;
            }
        }
        for(int i=left;i<=right;i++){
            zxfgg+=s[i];
            zzfgg+=t[i];
        }
        for(int i=0;i<n;i++){
            if(zq(zxfgg,chu[i])&&zq(s,chu[i])&&zq(zzfgg,mo[i])&&zq(t,mo[i])&&chu[i].size()>=zxfgg.size())ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
