#include<bits/stdc++.h>
using namespace std;

int n[1000005];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string a;
    long long j=0;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(0<=int(a[i]-'0')&&int(a[i]-'0')<=9){
            n[j]=int(a[i]-'0');
            ++j;
        }
    }
    sort(n, n+j);
    string ans;
    for(long long i=j-1;i>=0;i--){
        ans=ans+char(n[i]+'0');
    }
    cout<<ans;
    return 0;
}
