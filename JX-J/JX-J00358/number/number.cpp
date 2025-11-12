#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b=0,c[1000005],d,s;
    for(int i=0;i<1000005;i++){
        c[i]=10;
    }
    for(int i=0;i<a.length();i++){
        if(a[i]>='o'&&a[i]<='9'){
            b++;
            c[b]=int(a[i]);
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=b;j++){
            if(c[j]==i) cout<<i;
        }
    }
    cout<<a;
    return 0;
}
