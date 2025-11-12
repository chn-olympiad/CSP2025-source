#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],b;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            b++;
            a[b]=int(s[i])-48;
        }
    }
    sort(a+1,a+b+1);
    for(int i=b;i>0;i--) cout<<a[i];
    return 0;
}
