#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],x;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[i]=s[i]-'0';
            x++;
        }
        else continue;
    }
    sort(a,a+s.size(),greater<int>());
    for(int i=0;i<x;i++)
        cout<<a[i];
    return 0;
}
