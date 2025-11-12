#include<bits/stdc++.h>
using namespace std;
int a[10]={0};
string st;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>st;
    for(int i=0;i<st.length();i++)
    {
        if(st[i]>='0'&&st[i]<='9')
        {
            a[st[i]-'0']++;
        }
    }
    int i,j;
    for(int i=9;i>=0;i--)
    {
        if(a[i]!=0)
        {
            for(int j=1;j<=a[i];j++)
            {
                cout<<i;
            }
        }
    }
    return 0;
}
