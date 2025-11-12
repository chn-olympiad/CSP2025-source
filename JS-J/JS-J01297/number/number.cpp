#include<bits/stdc++.h>
using namespace std;
char ch;
int a[15];
int n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>ch){
        if(ch>='0'&&ch<='9') a[ch-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(a[i]--) cout<<i;
    }
    return 0;
}