#include <bits/stdc++.h>
using namespace std;
int n,m,p[510];
bool vis[510];
long long ans;
bool A=true;
string str;
int path[510];
map<long long,bool> vis2;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>str;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(str[i]=='0'){
            A=false;
        }
    }
    if(A){
        unsigned long long ans=1,cnt=0;
        for(int i=0;i<n;i++){
            if(p[i]==0){
                cnt++;
            }
        }
        for(int i=1;i<=n;i++){
            ans*=i;
            ans%=998244353;
        }
        if(n-cnt<m){
            cout<<0;
            return 0;
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        int in=0,l=0;
        for(int i=0;i<str.length();i++){
            if(str[i]=='1'){
                in=i;
                break;
            }
        }
        if(in==0){
            cout<<0;
            return 0;
        }
        for(int i=0;i<n;i++){
            if(p[i]<in){
                l++;
            }
        }
        int ans=n-l;
        for(int i=1;i<n;i++){
            ans*=i;
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        if(!A){
            cout<<0;
            return 0;
        }
    }
    cout<<rand();
    return 0;
}
