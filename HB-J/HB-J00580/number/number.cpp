#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005],k=0;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            k++;
            a[k]=s[i]-'0';
        }
    }
    sort(a+1,a+1+k);
    for(int i=k;i>=1;i--) cout<<a[i];
    return 0;
}
//290es1q0
//QwQ   qwq   :(   (@_@)   %(    #__#   b_b   O_O   D:

