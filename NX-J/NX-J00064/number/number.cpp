#include <bits/stdc++.h>
using namespace std;
string n;
char a[1000000];
int main()
{

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> n;
    for(int i=1;i<=strlen(n);i++)
    {
        if(n[i]>='0'&&n[i]<='9')
        {
           a[i]=n[i];
        }
    }
    for(int i=1;i<=strlen(n);i++)
    {
        cout << a[i];
    }
    return 0;
}