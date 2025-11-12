#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[105];
    for(int i=1;i<=6;i++)
    {
        b[i]=a%10;
        a=a/10;
    }
    sort(b[1],b[6+1]);
    for(int i=1;i<=7;i++)
    {
        printf("%d",&b[i]);
    }
    return 0;
}z
