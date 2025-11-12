#include<bits/stdc++.h>
using namespace std;
char c;
int cnt[10];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    while(cin>>c)
        if(isdigit(c))
            ++cnt[c-'0'];
    for(int i=9;i>=0;--i){
        c=i+'0';
        while(cnt[i]--)
            cout<<c;
    }
    return 0;
}
