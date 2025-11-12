#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,m;
    char b[100001];
    int c[100001]={0},n,v[100001];
    cin>>a;
    n=a.length();
    for(int i=0;i<=a.length()-1;i++){
        b[i]=a[i];
    }
    for(int i=0;i<=a.length()-1;i++){
        if(int(b[i])<'A'){
            c[i]=int(b[i]);
        }
    }

    for(int i=0;i<=n;i++){
        if(c[i]>0){
            cout<<char(c[i]);
        }
        else{
            break;
        }
    }
}
