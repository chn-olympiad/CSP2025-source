#include<bits/stdc++.h>
using namespace std;
char a[1000000];int b[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i=0;
    while(cin>>a[++i]){if (int(a[i]))b[int(a[i])++];}
    for(int j=10;j>=0;j--)
    {if(b[j])
    for(int k=b[j];k>0;k--)cout<<j;
    }
    return 0;
    
}
