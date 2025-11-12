#include<bits/stdc++.h>
using namespace std;
bool cmp(char x,char y)
{
    return x>y;
}
int main()
{
    freopen ("number.in","r",stdin);
    freopen ("number.out","w",stdout);
    string a;
    char b[1000001];
    cin>>a;
    int o=1;
    for (int i=0;i<a.size();i++)
    {
        if (a[i]>='0'&&a[i]<='9')
        {
           b[o]=a[i];
           o++;
        }
    }
    sort(b+1,b+o+1,cmp);
    string maxx;
    for (int i=1;i<=o;i++)
    {
        maxx+=b[i];
    }
    cout<<maxx;
    return 0;
}
