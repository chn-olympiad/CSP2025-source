#include<bits/stdc++.h>;
using namespace std;
int b[1000100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int n = sizeof(a);
    int o = 0;
    int q = 0;
    for(int i=0;i<=n;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            b[q] = int(a[i]);
            o++;
            q++;
        }
    }
    sort(b,b+o);
    for(int i = o;i>=0;i--)
    {
        cout << char(b[i]);
    }

}
