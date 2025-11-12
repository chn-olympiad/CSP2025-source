#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;int sl=0;int x;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            sl++;a[sl]=s[i]-'0';
        }
    }

    for(int i=1;i<sl;i++)
        for(int j=i+1;j<=sl;j++)
            if(a[i]<=a[j])
                swap(a[i],a[j]);
    for(int i=1;i<=sl;i++)
        cout<<a[i];
    return 0;
}
