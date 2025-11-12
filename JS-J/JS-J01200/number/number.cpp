#include<bits/stdc++.h>
using namespace std;
int a[1000009],sum=0;
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) {
        if(s[i]<='9'&&s[i]>='0') a[++sum]=s[i]-'0';
    }
    sort(a+1,a+sum+1);
    for(int i=sum;i>=1;i--) cout<<a[i];
    return 0;
}
