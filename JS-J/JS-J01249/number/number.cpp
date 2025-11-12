#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int a[maxn],cnt;
bool bj(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char x;
    while(cin>>x)
        if(x>='0'&&x<='9')
            a[++cnt]=x-48;
    sort(a+1,a+cnt+1,bj);
    for(int i=1;i<=cnt;i++)
        cout<<a[i];
    return 0;
}