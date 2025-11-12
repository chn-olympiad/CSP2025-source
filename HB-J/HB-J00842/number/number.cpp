#include <bits/stdc++.h>
using namespace std;
string a;
int len;
int book[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    len=a.size();
    for(int i=0;i<len;i++) if(a[i]>='0'&&a[i]<='9') book[a[i]-'0']++;
    for(int i=9;i>=0;i--) if(book[i]) for(int j=1;j<=book[i];j++) cout<<i;
    return 0;
}
