#include <bits/stdc++.h>
using namespace std;
int book[1000005],id;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("nuber.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            book[id++]=s[i]-'0';
        }
    }
    sort(book,book+id-1,cmp);
    for(int i=0;i<id;i++)
    {
        cout<<book[i];
    }
    return 0;
}
