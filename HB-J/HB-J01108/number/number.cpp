#include <bits/stdc++.h>
using namespace std;
int b[10005];
char a[10000005];
int main()
{
    freopen("number3.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >>a;
    int n=sizeof(a);
    int k=0;
    for (int i=1;i<=sizeof(a);i++)
    {
        if (a[i]>='0' &&a[i]<='9')
        {
            b[k]=a[i]-'0';
            k++;
        }
    }
    sort(b+1,b+k+1);
    for (int i=k;i>=1;i--)
    {
        cout <<b[i];


    }
}


