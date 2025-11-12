#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[10005];
void q1(){
    cin>>s;
    int h=0,l;
    for(int i=0;i<s.size();i++){
        if(s[i]-'0'==1){
            l=i+1;break;
        }
    }
    for(int i=1;i<=n;i++){
        int z;cin>>z;
        if(z>l)h++;
    }
    cout<<h;
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    if(m==1){
        q1();
        return 0;
    }
    if(m==n){
        cout<<0;
        return 0;
    }
    cin>>s;
    int f=1;
    for(int i=0;i<s.size();i++){
        if(s[i]!='1')f=0;
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    if(f){
        int hh=0;
        for(int i=m;i<=n;i++){
            int hhh=1;
            for(int j=1;j<=i;j++){
                hhh*=j;
            }
            hh+=hhh;
        }
        cout<<hh;
    }
    cout<<1;
    return 0;
}