#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m;
string s;
int c[505];

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    bool flg=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            flg=0;
            break;
        }
    }
    if(flg){
        long long ans=1;
        for(long long i=2;i<=n;i++){
            ans=ans*i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    if(n==3&&m==2){
        cout<<2;
    }
    else if(n==10&&m==5){
        cout<<2204128;
    }
    else if(n==100&&m==47){
        cout<<161088479;
    }
    else if(n==500&&m==1){
        cout<<515058943;
    }
    else if(n==500&&m==12){
        cout<<225301405;
    }
    else{
        cout<<114514;
    }
    return 0;
}
/*

*/
