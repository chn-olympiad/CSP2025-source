#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1000000];
    int num[10]={};
    cin >>a;
    for(int i=0;i<=strlen(a)-1;i++)
    {
        if(a[i]>=48&&a[i]<=57)
        {
            num[a[i]-48]++;
        }
    }
    int i=10;
    while(i)
    {
        if(num[i-1])
        {
            cout <<i-1;
            num[i-1]--;
        }
        else
        {
            i--;
        }
    }
    return 0;

}
