#include<bits/stdc++.h>
using namespace std;
int cnt[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //while(1) cout<<"Hello World.\n";
    string s;
    cin>>s;
    for(auto x:s)
        if('0'<=x&&x<='9') cnt[x-'0']++;
    for(int i=9;i>=0;i--)
        while(cnt[i]--) putchar(i+'0');
    return 0;
}
