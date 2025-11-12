#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;

struct node{
    int a,b,c;
    int jc;
}a[N];
ll ans;
int a1,b1,c1;
bool cmp(node x,node y)
{
    return x.jc>y.jc;
}
int mx;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        a1=0,b1=0,c1=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].jc=max(a[i].a,max(a[i].b,a[i].c))-min(a[i].a,min(a[i].b,a[i].c));
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            mx=max(a[i].a,max(a[i].b,a[i].c));
            if(a[i].a==mx)
            {
                if(a1>=n/2)
                {
                    if(a[i].b>a[i].c)
                    {
                        if(b1>=n/2)
                        {
                            ans+=a[i].c;
                            c1++;
                        }
                        else
                        {
                            ans+=a[i].b;
                            b1++;
                        }
                    }
                    else
                    {
                        if(c1>=n/2)
                        {
                            ans+=a[i].b;
                            b1++;
                        }
                        else
                        {
                            ans+=a[i].c;
                            c1++;
                        }
                    }
                }
                else{
                    ans+=a[i].a;
                    a1++;
                }
            }
            else if(a[i].b==mx)
            {
                if(b1>=n/2)
                {
                    if(a[i].a>a[i].c)
                    {
                        if(a1>=n/2)
                        {
                            ans+=a[i].c;
                            c1++;
                        }
                        else
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                    }
                    else
                    {
                        if(c1>=n/2)
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                        else
                        {
                            ans+=a[i].c;
                            c1++;
                        }
                    }
                }
                else{
                    ans+=a[i].b;
                    b1++;
                }
            }
            else if(a[i].c==mx)
            {
                if(c1>=n/2)
                {
                    if(a[i].b>a[i].a)
                    {
                        if(b1>=n/2)
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                        else
                        {
                            ans+=a[i].b;
                            b1++;
                        }
                    }
                    else
                    {
                        if(a1>=n/2)
                        {
                            ans+=a[i].b;
                            b1++;
                        }
                        else
                        {
                            ans+=a[i].a;
                            a1++;
                        }
                    }
                }
                else{
                    ans+=a[i].c;
                    c1++;
                }
            }

        }
        cout<<ans<<endl;
            ans=0;
    }
    return 0;
}
