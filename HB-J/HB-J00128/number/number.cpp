#include<bits/stdc++.h>
using namespace std;
#define int long long

string a;
int c[11];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a;
    for(int i=0;i<(int)a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            c[a[i]-'0']++;
        }
    }
    bool flag=1;
    for(int i=9;i>=0;i--){
        if(flag&&i==0)break;
        while(c[i]--){
            cout<<i;
            flag=0;
        }
    }
    if(flag){
        putchar('0');
    }
    return 0;
}