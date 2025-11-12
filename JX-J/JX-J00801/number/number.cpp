#include<bits/stdc++.h>
using namespace std;
string s, sn;
long long a[1000005], num, n0, n=1;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    getline(cin, s);
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9') {
                if(int(s[i]-'0')==0){
                    n0++;
                }
                else {a[n]=int(s[i]-'0');n++;}
        }
    }
    sort(a+1, a+n+1, [=](long long A, long long B){return A>=B;});
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(a[i]==0) break;
        flag=false;
        sn+=char(a[i]+'0');
    }
    if(flag) cout<<0;
    else {
        cout<<sn;
        for(int i=0;i<n0;i++){
            cout<<0;
        }
    }
    return 0;
}
