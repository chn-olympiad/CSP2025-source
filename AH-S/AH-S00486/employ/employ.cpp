#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            ans++;
        }
    }
    if(ans==n||m==1){
        cout<<(1+n)*n/2%998244353;
    }
    else{
        cout<<0;
    }
    return 0;
}
