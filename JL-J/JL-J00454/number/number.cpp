#include<bits/stdc++.h>
using namespace std;
    char a[10000];
    int b[10000],cnt=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='4'||a[i]=='3'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9')
        {
            b[cnt]=int(a[i]);
            cnt++;
        }
    }
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<cnt-i;j++)
            if(b[j]<b[j+1])
            {
                swap(b[j],b[j+1]);
            }
    }
    for(int i=0;i<cnt;i++)
    {
        cout<<b[i]-48;
    }
    return 0;
}
