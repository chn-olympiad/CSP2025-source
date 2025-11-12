#include<iostream>
#include<algorithm>
using namespace std;
int a[1000005],cur=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i] && s[i]<='9')
        {
            cur++;
            int k=int(s[i])-48;
            a[cur]=k;
        }
    }
    sort(a+1,a+cur+1,cmp);
    for(int i=1;i<=cur;i++)
    {
        cout<<a[i];
    }
}
