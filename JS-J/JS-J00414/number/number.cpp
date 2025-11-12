#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
void lesson1()
{
    char a[1000010];
    int b[1000010],k=0;
    cin>>a;
    for(int i=0;a[i]!='\0';i++)
    {
        if('0'<=a[i]&&a[i]<='9')
        {
            k++;
            b[k]=a[i]-'0';
        }
    }
    sort(b+1,b+1+k,cmp);
    for(int i=1;i<=k;i++)
    {
        cout<<b[i];
    }
}
int main()
{
    freopen(number.in,"r",stdin);
    freopen(number.out,"w",stdout);
    lesson1();
    return 0;
}
