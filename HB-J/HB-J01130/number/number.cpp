#include<bits/stdc++.h>
using namespace std;

string s;
int a[15];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(auto it:s)if('0'<=it&&it<='9')++a[it-'0'];
    for(int i=9;i>=0;--i)while(a[i]--)cout<<i;
    return 0;
}