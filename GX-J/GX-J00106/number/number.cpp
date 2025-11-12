#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char a[1000001];
long long b[1000001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long n,i,t=0;
    cin>>a;
    n=strlen(a);
    for(i=0;i<n;i++)
        if(a[i]>=48&&a[i]<=57){t++;b[t]=a[i]-48;}
    sort(b+1,b+t+1);
    for(i=t;i>0;i--)
        cout<<b[i];
    return 0;
}
