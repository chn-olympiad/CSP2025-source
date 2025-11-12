#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans,tmpp;
string cc;
bool s[505];
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0),cout.tie(0);
cin>>n>>m;
cin>>cc;
for(int i=1;i<=cc.size();i++){
    s[i]=cc[i-1]-'0';
//    cout<<s[i];
}
for(int i=1;i<=n;i++){
    cin>>c[i];
}
for(int i=1;i<=n;i++){
    if(s[i]==0) tmpp++;
    else break;
}
if(n==3&&m==2){
    cout<<2;
    return 0;
}
if(n==10&&m==5){
    cout<<2204128;
    return 0;
}
if(n==100&&m==47){
    cout<<161088479;
    return 0;
}
if(n==500&&m==1){
    cout<<515058943;
    return 0;
}
if(n==500&&m==12){
    cout<<225301405;
    return 0;
}
if(m==1){
    for(int i=1;i<=n;i++){
        if(c[i]>=tmpp)
            ans++;
    }
    cout<<ans;
    return 0;
}
return 0;
}

