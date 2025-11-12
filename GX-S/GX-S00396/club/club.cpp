#include<bits/stdc++.h>
using namespace std;
struct e
{
    int x,id;
}a[100000],b[100000],c[100000];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,h;
        cin>>n;
        h=n/2;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].x>>b[i].x>>c[i].x;
            a[i].id=i;
            b[i].id=i;
            c[i].id=i;
        }
        if(h==1)
        {
            cout<<max(a[0].x,max(b[0].x,c[0].x))+max(a[1].x,max(b[1].x,c[1].x))<<"\n";
            continue;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(a[j].x>a[j+1].x)
                {
                    swap(a[j],a[j+1]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(b[j].x>b[j+1].x)
                {
                    swap(b[j],b[j+1]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-1;j++)
            {
                if(c[j].x>c[j+1].x)
                {
                    swap(c[j],c[j+1]);
                }
            }
        }
        int a1=0,a2=0,a3=0;
        for(int i=0;i<h;i++)
        {
            if(a[0].x==0)
            {
                a1=0;
                break;
            }
            else
            {
                a1+=a[i].x;
            }
        }
        for(int i=0;i<h;i++)
        {
            if(b[0].x==0)
            {
                a2=0;
                break;
            }
            else
            {
                a2+=b[i].x;
            }
        }
        for(int i=0;i<h;i++)
        {
            if(c[0].x==0)
            {
                a3=0;
                break;
            }
            else
            {
                a3+=c[i].x;
            }
        }
        int ans=a1+a2+a3;
        cout<<ans<<"\n";
    }
    return 0;
}
