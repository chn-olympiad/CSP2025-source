#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int c=0;
    int n[100001]={};
    for(int i=0;i<a.size();i++){
        if(a[i]>='0' and a[i]<='9'){
            n[c]=a[i]-48;
            c++;
        }
    }
    sort(n,n+c);
    for(int i=c-1;i>=0;i--){
        cout<<n[i];
    }
    return 0;
}
