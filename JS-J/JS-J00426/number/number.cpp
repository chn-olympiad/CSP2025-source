#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main(){
    freopen("number.in",stdin);
    freopen("number.out",stdout);
    cin>>s;
    for(long unsigned int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=a[i];j++)cout<<i;
    return 0;
}
