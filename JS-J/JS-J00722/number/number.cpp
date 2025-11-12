#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int a[maxn];
int cnt=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a[cnt++]=s[i]-'0';
    }
    sort(a+1,a+cnt);
    for(int i=cnt-1;i>0;i--)
        cout<<a[i];
    return 0;
}
