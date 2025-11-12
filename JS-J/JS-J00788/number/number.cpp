#include<bits/stdc++.h>
using namespace std;
int f[15],a[1000010],idx;
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++){
        if (int(s[i]) >= int('0') && int(s[i]) <= int('9')){
            f[int(s[i])- int('0')]++;
        }
    }
    for(int i=10;i>=0;i--){
        if (f[i] >0 ){
            for(int j=0;j<f[i];j++) a[idx++]=i;
        }
    }
    for(int i=0;i<idx;i++){
        cout<<a[i];
    }

    return 0;
}
