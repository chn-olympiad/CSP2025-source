#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("nmuber.out","w",stdout);
    string a;
    cin>>a;
    long long sz[10]={};
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            sz[a[i]-48]++;
        }
    }
    string s="";
    for(int i=9;i>=0;i--){
        for(int j=1;j<=sz[i];j++){
            s+=char(i+48);
        }
    }
    cout<<s;
    return 0;
}
