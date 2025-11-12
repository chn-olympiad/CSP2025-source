#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int num[1000006];
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    int c=0;
    for(int i=0;i<s.size();i++){
        if(s[i]<='9'&&s[i]>='0'){
            num[++c]=s[i]-'0';
        }
    }
    sort(num+1,num+c+1);
    if(num[c]==0){
        cout<<0;return 0;
    }
    for(int i=c;i>=1;i--){
        cout<<num[i];
    }
    return 0;
}
