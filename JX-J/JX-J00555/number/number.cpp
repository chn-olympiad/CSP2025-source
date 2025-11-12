#include <bits/stdc++.h>
using namespace std;
string a;
long long s = 0,b[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(long long i = 0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[s]=a[i]-'0';
            cout<<a[i]-'0'<<" ";
            s++;
        }
    }
    sort(b,b+s);
    if(s==1){
        cout<<b[0];
    }
    else{
        for(long long i = s-1;i>=0;i--){
            cout<<b[i];
        }
    }
    return 0;
}
