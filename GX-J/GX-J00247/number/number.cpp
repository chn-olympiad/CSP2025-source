#include<bits/stdc++.h>
using namespace std;
long long a[1000001],sz=1;
bool cmp(int a,int b)
{
    if(a!=b) return a>b;

}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[sz]=s[i]-'0';
            sz++;
        }
    }
    sort(a+1,a+1+sz,cmp);
    for(int i=1;i<=sz-1;i++)
    {

        cout<<a[i];
    }

  return 0;
}
