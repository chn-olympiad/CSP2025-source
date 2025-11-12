#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
LL a[1000000+10];
LL n;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[++n]=s[i]-'0';
        }
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}
