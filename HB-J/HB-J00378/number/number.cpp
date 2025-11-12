#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[110000]={};
    cin>>a;
    int b[110000]={};
    int cnt=0;
    for(int i=0;i<=strlen(a)-1;i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            cnt++;
            b[cnt]=a[i];
        }
    }
    for(int i=cnt;i>=1;i--)
    {
        b[i]-=48;

    }
    sort(b+0,b+cnt+1);
    for(int i=cnt;i>=1;i--)
    {

        cout<<b[i];
    }
    return 0;
}
