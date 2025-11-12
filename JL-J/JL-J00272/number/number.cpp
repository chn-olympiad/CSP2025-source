#include<bits/stdc++.h>
using namespace std;
string a;
long long n[1000010],t=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            n[t]=int(a[i]-'0');
            t++;
        }
    }
    sort(n,n+t);
    for(int i=t-1;i>=0;i--){
        cout<<n[i];
    }
    return 0;
}
