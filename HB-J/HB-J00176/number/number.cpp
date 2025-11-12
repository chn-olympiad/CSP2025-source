#include <bits/stdc++.h>
using namespace std;
string a;
char b[1000005];
int idx;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin>>a;
    for(int i=0;i<int(a.size());i++)
        if(a[i]>='0' && a[i]<='9')
            b[idx++]=a[i];
    sort(b,b+idx-1,greater<char>());
    printf("%s",b);
    return 0;
}
