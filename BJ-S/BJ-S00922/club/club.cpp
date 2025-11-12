#include<bits/stdc++.h>
using namespace std;
struct ren
{
    int a[4];
    int mx,cha;
}s[100005];
bool cmp(ren x,ren y)
{
    return x.cha<y.cha;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        int i,j,k;
        cin>>n;
        vector<ren> a,b,c;
        int ans=0;
        for(i=1;i<=n;i++)
        {
            int x,y,z;
            cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
            x=s[i].a[1];
            y=s[i].a[2];
            z=s[i].a[3];
            sort(s[i].a+1,s[i].a+4);
            s[i].cha=s[i].a[3]-s[i].a[2];
            if(s[i].a[3]==x)
            {
                a.push_back(s[i]);
                ans+=x;
            }
            else if(s[i].a[3]==y)
            {
                b.push_back(s[i]);
                ans+=y;
            }
            else if(s[i].a[3]==z)
            {
                c.push_back(s[i]);
                ans+=z;
            }
        }
        if(a.size()>n/2)
        {
            sort(a.begin(),a.end(),cmp);
            for(i=0;i<a.size()-n/2;i++)
            {
                ans-=a[i].cha;
            }
        }
        else if(b.size()>n/2)
        {
            sort(b.begin(),b.end(),cmp);
            for(i=0;i<b.size()-n/2;i++)
            {
                ans-=b[i].cha;
            }
        }
        else if(c.size()>n/2)
        {
            sort(c.begin(),c.end(),cmp);
            for(i=0;i<c.size()-n/2;i++)
            {
                ans-=c[i].cha;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
