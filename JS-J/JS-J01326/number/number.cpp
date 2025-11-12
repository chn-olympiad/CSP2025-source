#include<bits/stdc++.h>
using namespace std;
long long a,c[100005],d=0,i;
string b;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    a=b.size();
    for(i=0;i<a;i++)
    {
        if(b[i]>='0' && b[i]<='9')
        {
            d++;
            c[d]=b[i]-'0';
        }
    }
    sort(c+1,c+d+1,cmp);
    for(i=1;i<=d;i++)
    {
        cout<<c[i];
    }
    return 0;
}
