#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000005],now=0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[now]=s[i]-'0';
            now++;
        }
    }
    sort(a,a+now,cmp);
    for(int i=0;i<now;i++){
        cout<<a[i];
    }
    return 0;
}
//
