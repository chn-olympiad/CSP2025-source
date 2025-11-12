#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s;
int a[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int j=0;
    for(int i=0;i<=s.size();i++) if(s[i]>='0' && s[i]<='9') a[j++]=s[i]-'0';
    sort(a,a+j);
    for(int i=j-1;i>=0;i--) printf("%d",a[i]);
    return 0;
}
