#include<bits/stdc++.h>
using namespace std;
int s[100009],n,x,ans;
struct l
{
    int a,b,c;
};
l h[100009];
void m(int o,int a,int b,int c,int sum)
{
    if(o==x+1)
    {
        ans=max(sum,ans);
        return;
    }
    for(int i=1;i<=x;i++)
    {
        if(!s[i])
        {
            if(a<x/2)
            {
                s[i]=1;
                m(o+1,a+1,b,c,sum+h[i].a);
                s[i]=0;
            }
            if(b<x/2)
            {
                s[i]=1;
                m(o+1,a,b+1,c,sum+h[i].b);
                s[i]=0;
            }
            if(c<x/2)
            {
                s[i]=1;
                m(o+1,a,b,c+1,sum+h[i].c);
                s[i]=0;
            }
        }
    }
}
int main()
{
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        for(int j=1;j<=x;j++)
            cin>>h[j].a>>h[j].b>>h[j].c;
        ans=0;
        m(1,0,0,0,0);
        cout<<ans<<endl;
    }
}
