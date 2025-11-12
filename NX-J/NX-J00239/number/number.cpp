#include <bits/stdc++.h>
using namespace std;
int shu[1005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int l=1;
    cin >> a;
    for(int i=0;i<=a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            int n=a[i]-'0';
            shu[l]=n;
            l++;
        }
    }
    for(int i=1;i<=l-1;i++)
    {
        for(int j=1;j<=l-1-i;j++)
        {
            if(shu[j]<shu[j+1])
            {
                swap(shu[j],shu[j+1]);
            }
        }
    }
    for(int i=1;i<=l-1;i++)
    {
        cout << shu[i];
    }
    return 0;
}
