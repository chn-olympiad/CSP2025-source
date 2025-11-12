#include <bits/stdc++.h>
using namespace std;
string n;
long long a[20],i;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n;
    for (i=1;i<=n.size();i++)
    {
        if (n[i-1]>='0'&&n[i-1]<='9')
        {
            a[n[i-1]-'0']++;
        }
    }
    for (i=9;i>=0;i--)
    {
        while (a[i])
        {
            cout<<i;
            a[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
