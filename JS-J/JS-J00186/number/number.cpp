#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[11],state;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            int p=s[i]-'0';
            a[p]++;
        }
    }
    for(int i=9;i>=1;i--){
        while(a[i]){
            cout<<i;
            a[i]--;
            state=1;
        }
    }
    if(state==1&&a[0]){
        while(a[0]){
            cout<<0;
            a[0]--;
        }
    }
    else if(a[0]&&state==0){
        cout<<0;
    }
    return 0;
}
