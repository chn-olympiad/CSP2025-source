#include<bits/stdc++.h>
#define IO(name) freopen(name".in","r",stdin),freopen(name".out","w",stdout)
using namespace std;
string s;
int a[1000005],t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    IO("number");
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            a[t++]=s[i]-'0';
    sort(a,a+t,greater<int>());
    for(int i=0;i<t;i++) cout<<a[i];
    return 0;
}
