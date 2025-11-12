#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[15];
string s;
int l;
bool f=1;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++){
        if(!(s[i]>='0'&&s[i]<='9')) continue;
        a[s[i]-'0']++;
    }
    for(int i=1;i<=9;i++){
        if(a[i]){
            f=0;
            break;
        }
    }
    if(f){
        cout<<0;
        return 0;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            cout<<i;
        }
    }
    return 0;
}
