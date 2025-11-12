#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char c;
    int p=1;
    while(cin>>c)
    {
        if(isdigit(c))    a[p++]=c-'0';
    }
    sort(a+1,a+p);
    for(int i=p-1;i>0;i--)    cout<<a[i];
    return 0;
}
