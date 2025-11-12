#include<bits/stdc++.h>
using namespace std;
bool cmp(int aaa,int bbb)
{
    return aaa>bbb;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string ss;
    cin>>ss;
    int sl=0,sz[1000006];
    bool f=1;
    for(int i=0;i<ss.size();i++)
    {
        if(ss[i]>='0'&&ss[i]<='9')
        {
            sz[++sl]=ss[i]-'0';
            if(sz[sl]!=0)
            {
                f=0;
            }
        }
    }
    sort(sz+1,sz+sl+1,cmp);
    if(f==1) cout<<0;
    else
    {
        for(int i=1;i<=sl;i++)
        {
            cout<<sz[i];
        }
    }
    return 0;
}
