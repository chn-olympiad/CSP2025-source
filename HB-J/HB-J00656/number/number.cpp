#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    long long x=s.length(),cnt=0;
    for(long long i=0;i<x;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[cnt]=int(s[i])-48;
            cnt++;
        }
    }
    sort(a,a+cnt);
    reverse(a,a+cnt);
    for(long long i=0;i<cnt;i++){
        cout<<a[i];
    }
    return 0;
}
