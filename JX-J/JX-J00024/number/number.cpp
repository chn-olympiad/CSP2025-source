#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;
string a,c;
int b[1000010],sz,ans;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]<='9'&&a[i]>='0'){
        b[sz++]=a[i]-48;
        }
    }
    sort(b,b+sz);
    for(int i=sz-1;i>=0;i--){
    c+=b[i]+48;
    }
    cout<<c;
    return 0;
}