#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int l=s.size(),a[l];
    memset(a,-1,sizeof(a));
    for(int i=0;i<l;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i]-'0';
        }
    }
    sort(a,a+l);
    int i=l-1;
    while(i>=0)
    {
        if(a[i]!=-1)
        {
            cout<<a[i];
            i--;
        }else{
            i--;
            continue;
        }
    }
    return 0;
}
