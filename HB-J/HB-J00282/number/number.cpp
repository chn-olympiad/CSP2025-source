#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    cin>>n;
    int a[1000005];
    int len=n.size(),top=1;
    for(int i=0;i<len;i++)
    {
        if(n[i]>='0'&&n[i]<='9')
            a[top++]=n[i]-'0';
    }
    sort(a+1,a+top,cmp);
    for(int i=1;i<top;i++)
    {
        cout<<a[i];
    }
    return 0;
}
