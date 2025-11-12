#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;int x=0;
    int a[10000];
    for(int i=0;i<s.size();i++){
        if(48<=s[i]&&s[i]<=57){a[++x]=s[i]-48;}
    };
    sort(a+1,a+x+1);
    for(int j=x;j>=1;j--)cout<<a[j];
    return 0;
}
