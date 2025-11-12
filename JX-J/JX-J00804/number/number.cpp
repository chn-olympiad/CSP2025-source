#include<bits/stdc++.h>
using namespace std;
string a;
int b[1111],c=-1;
int cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            c+=1;
            b[c]=a[i]-48;
        }
    }
    sort(b,b+c,cmp);
    for(int i=0;i<=c;i++)
    {
        cout<<b[i];
    }
    return 0;
}
