#include<bits/stdc++.h>
using namespace std;
int a[1000005],p;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')
            a[++p]=int(s[i]-'0');
    }
    sort(a+1,a+p+1);
    for(int i=p;i>=1;i--) cout<<a[i];
    return 0;
}
