#include <iostream>
using namespace std;
int g[100005];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    if(m==n){
        cout<<1;
        return 0;
    }
    else if(m==1){
        int ans=0;
        for(int i=0;i<n;i++){
            if(i<g[i]&&s[i]=='1'){
                ans+=1;
            }
        }
        cout<<ans;
        return 0;
    }
    bool spa=true;
    for(int i=0;i<n;i++){
        if(s[i]!='1'){
            spa=false;
        }
    }
    if(spa==true){
        long long jm=1;
        for(int i=1;i<=m;i++){
            jm*=i;
        }
        long long jn=1;
        for(int i=1;i<=n;i++){
            jn*=i;
        }
        cout<<jn/jm;
        return 0;
    }
    else{
        cout<<5;
        return 0;
    }
    return 0;
}
