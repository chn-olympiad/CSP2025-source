#include <bits/stdc++.h>
using namespace std;
int a[1000001];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    int s=0;
    cin>>n;
    for(int i=0;i<n.length();i++)
    {
        if(!(isalpha(n[i])))
        {
            s++;
            a[s]=int(n[i])-48;
        }
    }
    sort(a+1,a+s+1,cmp);
    for(int i=1;i<=s;i++)
    {
        cout<<a[i];
    }
    return 0;
}
