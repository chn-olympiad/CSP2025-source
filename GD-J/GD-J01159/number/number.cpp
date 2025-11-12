#include<bits/stdc++.h>
using namespace std;
long long a[10];
char c;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    c=getchar();
    while((c>='a'&&c<='z')||(c>='0'&&c<='9'))
    {
        if(c>='0'&&c<='9')a[c-'0']++;
        c=getchar();
    }
    for(int i=9;i>=0;i--)
    while(a[i]--)putchar(i+'0');
}