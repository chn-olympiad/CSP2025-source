#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];
int k;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[k]=s[i]-'0';
            k++;
        }
    }
    sort(a,a+n,cmp);
    string p="";
    for(int i=0;i<k;i++)
    {
        p+=(a[i]+'0');
    }
    cout<<p;
    return 0;
}
