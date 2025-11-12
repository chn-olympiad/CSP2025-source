#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[1000005],n,b,c[1000005][1005],e=0;
string s[1000005];
int fo(int x,int l){
    e=0;
    if(x==l){
        int d=0;
        for(int i=1;i<=l;i++){
            d+=c[1][i];
        }
        for(int i=1;i<=l;i++){
            if(c[1][i]>=d)return 0;
        }
        e++;
        return e;
    }
    for(int i=1;i<=n;i++){
        c[1][x]=a[i];
        return fo(x+1,l);
    }
}
int main(){
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=3;i<=n;i++){
        e+=fo(1,i);
    }
    cout << e;
    return 0;
}

