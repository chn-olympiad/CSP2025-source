#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000010],cnt;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }sort(a,a+cnt,greater<int>());
    if(a[0]==0){
        cout<<0;
    }else{
        for(int i=0;i<cnt;i++){
            cout<<a[i];
        }
    }
    return 0;
}
