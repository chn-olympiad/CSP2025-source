#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[10005],c;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            a[++c]=s[i]-'0';
    }
    sort(a+1,a+c+1);
    for(int i=c;i>0;i--)
        cout<<a[i];
    return 0;
}
