#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in",r,stdin);
    freopen("number.out",w,stdout);
    string a;
    cin>>a;
    int cnt=0;
    string b;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9') b+=a[i];
    }

    int bo[b.size()]={0};
    for(int i=0;i<b.size();i++){
        bo[i]=b[i]-'0';
    }
    sort(bo,bo+b.size());
    for(int i=b.size()-1;i>=0;i--) cout<<bo[i];
    return 0;
}

