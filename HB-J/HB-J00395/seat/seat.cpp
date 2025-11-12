#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int a[105],l[105],h[105],rgrade=0;
priority_queue<int> pq;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int r;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1) r=a[i];
        pq.push(a[i]);
    }
    //cout<<r<<endl;
    //for(int i=1;i<=n*m;i++) cout<<pq.top()<<" ",pq.pop();
    for(int i=1;i<=n*m;i++)
    {
        a[i]=pq.top();
        pq.pop();
    }
    //for(int i=1;i<=n*m;i++) cout<<a[i]<<" ";
    for(int i=1;i<=n*m;i++)
    {
        if(i==1) l[i]=1,h[i]=1;
        else
        {
            if(h[i-1]<n)
            {
                if(i==2||h[i-2]<h[i-1])
                {
                    l[i]=l[i-1];
                    h[i]=h[i-1]+1;
                }
                else if(h[i-2]>h[i-1])
                {
                   if(h[i-1]==1) h[i]=1,l[i]=l[i-1]+1;
                   else l[i]=l[i-1],h[i]=h[i-1]-1;
                }
                else
                {
                    if(h[i-1]=1) l[i]=l[i-1],h[i]=h[i-1]+1;
                    else l[i]=l[i-1],h[i]=h[i-1]-1;
                }
            }
            else if(h[i-1]==n)
            {
                if(l[i-1]==m) l[i]=l[i-1],h[i]=h[i-1]-1;
                else if(h[i-2]<h[i-1]) l[i]=l[i-1]+1,h[i]=h[i-1];
                else
                {
                    l[i]=l[i-1];
                    h[i]=h[i-1]-1;
                }
            }
        }
        if(a[i]==r)
        {
            cout<<l[i]<<" "<<h[i];
            return 0;
        }
        //cout<<l[i]<<" "<<h[i]<<endl;
    }
    return 0;
}
