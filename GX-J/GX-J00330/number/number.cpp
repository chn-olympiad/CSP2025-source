#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[10000],b=1;
    for(int i=1;i<=30;i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[b]=s[i];
            b++;
        }
    }
    for(int i=1;i<=b;i++){
        if(a[i]<a[i+1])swap(a[i],a[i+1]);
    }
    for(int i=1;i<=b;i++){
            cout<<a[i];
    }
    return 0;
}
