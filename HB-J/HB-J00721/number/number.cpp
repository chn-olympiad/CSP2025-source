#include <bits/stdc++.h>
using namespace std;
int book[1000005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a;
    int i=0;
    while(cin>>a)
    {
        if(a-'0'>=0&&a-'0'<=9)
        {
            book[i]=a-'0';
            i++;
        }
    }
    sort(book,book+i,cmp);
    for(int j=0;j<i;j++)
    {
        cout<<book[j];
    }
    return 0;
}
