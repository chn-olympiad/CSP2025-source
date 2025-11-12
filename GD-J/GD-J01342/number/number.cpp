#include<bits/stdc++.h>
using namespace std;
#define int long long 
int cnt;
string s;
int a[1000005];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin,s);
    for(int i=0;i<s.size();){
        if(s[i]>='0'&&s[i]<='9'){
            a[++cnt]=s[i++]-'0';
            continue;
        }
        else{
            s.erase(i,1);
        }
    }
    sort(a+1,a+cnt+1,greater<int>());
    for(int i=1;i<=cnt;i++){
        cout<<a[i];
    }
    return 0;
}
