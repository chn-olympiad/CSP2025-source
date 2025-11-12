#include <bits/stdc++.h>
using namespace std;
string s;
unsigned long long a[10001];
unsigned long long p[100001];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    unsigned long long n=s.size();
    memset(p,-1,sizeof(p));
    for(int i=0;i<n;i++)
    {
        a[i]=s[i]-'0';
    }
    unsigned long long k=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0||a[i]==1||a[i]==2||a[i]==3||a[i]==4||a[i]==5||a[i]==6||a[i]==7||a[i]==8||a[i]==9)
        {
            p[k]=a[i];
            k++;
        }
    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        if(p[i]!=-1) cout<<p[i];
        else break;
    }
    return 0;
}
