#include<bits/stdc++.h>
using namespace std;
string s;
int x=0;
long long a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    getline(cin,s);
    for(int i=0;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            x++;
            a[x]=s[i]-'0';
        }
    }
    sort(a,a+x+1);
    int z=a[x];
    for(int i=x-1;i>=1;i--)
    {
        z=z*10+a[i];
    }
    cout<<z;
    return 0;
}
