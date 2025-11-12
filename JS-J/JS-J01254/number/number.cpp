#include<bits/stdc++.h>
using namespace std;
int b[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int c,i=0;
    cin>>a;
    for(int k=0;k<a.size();k++){
        c=a[k]-'0';
        if(c<0||c>9)continue;
        b[c]++;
    }
    int d=0;
    for(int k2=0;k2<=9;k2++){
        for(int k3=0;k3<b[k2];k3++){
            cout<<k2;
            i++;
        }
    }
    return 0;
}

