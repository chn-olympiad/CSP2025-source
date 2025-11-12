#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(char ch:s)
        if(ch>='0'&&ch<='9')
            a[ch-'0']++;
    for(int i=9;i>=0;i--)
        while(a[i]--)
            cout<<i;
    cout<<'\n';
    return 0;
}