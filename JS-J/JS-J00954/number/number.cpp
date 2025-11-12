#include<bits/stdc++.h>
using namespace std;
string a;int b[10];
int main(){
    ios::sync_with_stdio(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
        if(isdigit(a[i])) b[a[i]-48]++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=b[i];j++)
            cout<<i;
    return 0;
    }
