#include<bits/stdc++.h>
using namespace std;
string s;
int n[100005];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int m=0;
    while(s[m]!='\0')
        m++;
    int j=0;
    for(int i=0;i<=m;i++)
        if(s[i]>='0' && s[i]<='9')
        {
            j++;
            n[j]=s[i]-'0';
        }
    sort(n+1,n+1+j,cmp);
    for(int i=1;i<=j;i++)
        cout<<n[i];;
    return 0;
}
