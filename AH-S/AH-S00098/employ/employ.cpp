#include<bits/stdc++.h>
using namespace std;
int c[510],n,m,f;
string s;
int main(){
    freopen("exploy.in","r",stdin);
    freopen("exploy.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') f++;
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    if(f+m>n){
        cout<<"0";
    }else{
        long long a=1;
        for(int i=1;i<=n;i++){
            a=a%998244353*i;
        }
        cout<<a;
    }
    return 0;
}
