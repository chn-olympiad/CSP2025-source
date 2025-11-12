#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int tot=0;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if('0'<=s[i] && s[i]<='9')
        {

            a[++tot]=(s[i]-'0');
        }
    }
    sort(a+1,a+tot+1);
    for(int i=tot;i>=1;i--)
        cout<<a[i];
}
