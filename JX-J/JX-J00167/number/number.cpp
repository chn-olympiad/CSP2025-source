#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000000];
int b[1000000];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int k=0;
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[k]=s[i];
            k++;
        }
    }
    for(int i=0;i<k;i++) b[i]=a[i]-'0';
    sort(b,b+k,cmp);
    for(int i=0;i<k;i++) cout<<b[i];
    return 0;
}
