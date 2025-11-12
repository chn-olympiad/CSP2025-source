#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int sum=0,t=0,b[100000];
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        if(a[i]>='0'&&a[i]<='9'){
            b[t]=a[i]-48;
            t++;
        }
    }
    sort(b,b+t);
    for(int i=t-1;i>=0;i--){
        cout<<b[i];
    }
    return 0;
}
