#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int u=1;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[u]=int(s[i]-'0');
            u++;
        }
    }
    sort(a+1,a+1+u);
    reverse(a+1,a+1+u);
    for(int i=1;i<u;i++){
        cout<<a[i];
    }
    return 0;
}
