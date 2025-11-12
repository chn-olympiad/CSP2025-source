#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int a[N],num=1;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[num]=s[i]-'0';
            num++;
        }
    }
    sort(a+1,a+num,cmp);
    for(int i=1;i<num;i++) cout<<a[i];
    return 0;
}
