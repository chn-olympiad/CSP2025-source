#include<bits/stdc++.h>
using namespace std;
const int mx=1E6+10;
int a[mx],cnt;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++)
        if('0'<=s[i]&&s[i]<='9')
            a[cnt++]=s[i]-'0';
    sort(a,a+cnt);
    for(int i=cnt-1;i>=0;i--)
        cout<<a[i];
    return 0;
}
