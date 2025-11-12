#include<bits/stdc++.h>
using namespace std;

#define ll long long

int a[1000010],p=0;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++) if(s[i]>='0'&&s[i]<='9') a[p++]=s[i]-'0';
    sort(a,a+p);
    for(int i=p-1;i>=0;i--) cout<<a[i];
    return 0;
}
