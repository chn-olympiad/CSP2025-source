#include <bits/stdc++.h>
using namespace std;

int main()
{freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string s[1005],a[1005];
for(int i=1;i<=1005;i++)
{
    cin >> s[i];
        if('s[i]'>='0' && 's[i]'<='9')
            a[i]=s[i];
}
for(int i=1;i<=1005;i++)
{
    if(a[i]>=a[i-1]) a[i]=a[i-1];cout << a[i];
}

return 0;
}
