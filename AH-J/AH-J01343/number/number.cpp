#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
string s;
int n,a[maxn]={0},j=0;
bool cmp(int x,int y)
{

    return x>y;
}
int main(void)
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[j]=s[i]-'0';

            j++;
        }
    }
    sort(a,a+j,cmp);
    for(int i=0;i<j;i++)
    {
        cout<<a[i];
    }return 0;
}
