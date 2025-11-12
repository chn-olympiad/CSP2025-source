#include<bits/stdc++.h>
using namespace std;
int n,bj[505],k,cnt;
string s1;
struct node{
    char si;
    int ai;
}c[505];
stack<node>s;
bool chack()
{
    vector<node>v;
    int sum=0;
    while(s.size())
    {
        v.push_back(s.top());
        s.pop();
    }
    int cnt1=0;
    for(int i=1;i<=v.size();i++)
    {
        s.push(v[i]);
        if(v[i].ai<=cnt1&&v[i].si!='0')
        {
            sum++,cnt=0;
        }
        else cnt1++;
    }
    if(sum>=k) return 1;
    return 0;
}
void f(int x,int y)
{
    if(x==y)
    {
        if(chack()==1) cnt=(cnt+1)%998244353;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            s.push(c[i]);
            bj[i]=1;
            f(x+1,y);
            s.pop();
            bj[i]=0;
        }
    }
}
int main()
{
    freopen("employ1.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>c[i].si;
    for(int i=1;i<=n;i++) cin>>c[i].ai;
    f(0,n);
    cout<<cnt;
    return 0;
}
//zuei yuong xin xie de di er ge
//55
