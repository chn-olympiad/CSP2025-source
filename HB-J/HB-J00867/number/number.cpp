#include <bits/stdc++.h>
using namespace std;
int book[1000005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin >> a;
    int len=a.size(),x=0;
    for(int i=0;i<len;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            book[x++]=a[i]-'0';
        }
    }
    sort(book,book+x,cmp);
    for(int i=0;i<x;i++)
    {
        cout << book[i];
    }
    cout << endl;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
