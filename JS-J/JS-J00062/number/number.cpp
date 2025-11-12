#include<bits/stdc++.h>
using namespace std;
string q;
int x[1000005],s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>q;
    for(int i=0;i<q.size();++i)
    {
        if(q[i]>='0' && q[i]<='9')
        {
            x[s]=int(q[i]-'0');s++;
        }
    }sort(x,x+s);
    for(int i=s-1;i>=0;i--)
    {
        cout<<x[i];
    }
    return 0;
}
