#include<bits/stdc++.h>
using namespace std;
int b[1000005],bi;
bool c(int a,int b){
    return a>b;
}
int main(){
    string a;
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[bi]=a[i]-'0';
            bi++;
        }
    }
    sort(b,b+bi,c);
    for(int i=0;i<bi;i++){
        cout<<b[i];
    }
    return 0;
}
