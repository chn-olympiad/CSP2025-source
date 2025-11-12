#include<bits/stdc++.h>
#define ftsydj 114514
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1000010];
    int n,i,j,a[68];
    cin>>s;
    for(i=0;i<strlen(s);++i)
        if(isdigit(s[i]))a[s[i]-'0']++;
    for(i=9;i>=0;--i)
        if(a[i]>0)
            for(j=1;j<=a[i];++j)cout<<i;
    cout<<endl;
    return 0;
}
