#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000005],a[1000005];
ll sum;

bool cmp(char a,char b)
{
    return a>b;
}

int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    const char endl='\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    //------------
    cin.get(s,1000005);
    ll i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[sum++]=s[i];
        }
        i++;
    }
    sort(a,a+sum,cmp);
    for (int k=0;k<sum;k++)
    {
        cout<<a[k];
    }
    return 0;
}
