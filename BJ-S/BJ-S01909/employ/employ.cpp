#include<bits/stdc++.h>
using namespace std;

int n,m,s[505]={},c[505];
long long p[505];
string sf;

int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    p[0] = 1;
    for(int i=1;i<=500;i++){
        p[i] = ((p[i-1]*i)%998244353+998244353)%998244353;
    }
    cin>> n >> m;
    cin>> sf;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        s[i+1] = s[i]+sf[i]-48;
    }
    if(m == n){
        if(s[n] == n){
            cout<< p[n];
        }
        else{
            cout<<0;
        }
        return 0;
    }
    if(s[n] == n){
        cout<< p[n];
        return 0;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
    
}