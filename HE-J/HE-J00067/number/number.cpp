#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

string a;
int b[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> a;
    int n=a.size();
    int y=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            y++;
            b[y]=a[i];
        }
    }
    sort(b+1,b+1+y);
    for(int i=y;i>=1;i--)
    {
        cout << char(b[i]);
    }
    return 0;
}
