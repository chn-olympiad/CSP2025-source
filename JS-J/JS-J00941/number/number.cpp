#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
long long cnt[N],top,sum;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<=s.size()-1;i++){
        if(s[i]<='z'&&s[i]>='a') continue;
        top++;
        if(s[i]=='1') cnt[top]=1;
        if(s[i]=='2') cnt[top]=2;
        if(s[i]=='3') cnt[top]=3;
        if(s[i]=='4') cnt[top]=4;
        if(s[i]=='5') cnt[top]=5;
        if(s[i]=='6') cnt[top]=6;
        if(s[i]=='7') cnt[top]=7;
        if(s[i]=='8') cnt[top]=8;
        if(s[i]=='9') cnt[top]=9;
    }
    sort(cnt+1,cnt+top+1);
    for(int i=top;i>=1;i--){
        cout<<cnt[i];
    }
    return 0;
}
