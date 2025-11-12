#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],len;
bool cmp(int x,int y)
{

    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int now=s.size();
    for(int i=0;i<now;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            len++;
            a[len]=s[i]-'0';
        }
    }
    sort(a+1,a+len+1,cmp);
    for(int i=1;i<=len;i++)
        printf("%d",a[i]);
    return 0;
}
