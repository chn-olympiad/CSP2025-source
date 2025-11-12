#include <bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int cnt=1;
    cin>>s;
    int shu[1000005]={ },lee=s.size();
    for(int i=0;i<lee;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            shu[cnt]=s[i]-48;
            cnt++;
        }
    }
    sort(shu+1,shu+cnt,cmp);
    for(int i=1;i<cnt;i++)cout<<shu[i];

    return 0;
}
