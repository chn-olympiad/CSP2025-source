#include<bits/stdc++.h>
#define int long long
using namespace std;
string b[1145141];
string a[1145141];
string s;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.length();
    if(len==1){
        cout<<s;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<len;i++){
        a[i]=s[i];
        if(a[i]>="a"&&a[i]<="z") continue;
        else b[cnt++]=a[i];
    }
    sort(b,b+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
