#include <bits/stdc++.h>
using namespace std;

string s;
int a[1000010],q=0;
int n;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            q++;
            a[q]=s[i]-'0';
        }
    }
    sort(a+1,a+1+q,cmp);
    for(int i=1;i<=q;i++)
    {
        cout<<a[i];
    }
    return 0;
}
