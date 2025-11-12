#include<bits/stdc++.h>
using namespace std;
struct text
{
    int a,b,c,t;
};
vector<text> v1,v2,v3;
text a[100005];
bool cmp1(text a,text b)
{
    return a.a-a.b<b.a-b.b;
}
bool cmp2(text a,text b)
{
    return a.b-a.c<b.b-b.c;
}
bool cmp3(text a,text b)
{
    return a.c-a.a<b.c-b.a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        v1.clear(),v2.clear(),v3.clear();
        memset(a,0,sizeof(0));
        int n;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].t=i;
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
            {
                v1.push_back(a[i]);
                a[i].t=1;
            }
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
            {
                v2.push_back(a[i]);
                a[i].t=2;
            }
            else
            {
                v3.push_back(a[i]);
                a[i].t=3;
            }
        }
        if(v1.size()>n/2)
        {
            sort(v1.begin(),v1.end(),cmp1);
            for(int i=0;i<v1.size()-n/2;++i)
            {
                a[v1[i].t].t=2;
                v2.push_back(v1[i]);
            }
            if(v2.size()>n/2)
            {
                sort(v2.begin(),v2.end(),cmp2);
                for(int i=0;i<v2.size()-n/2;++i)
                {
                    a[v2[i].t].t=3;
                    v3.push_back(v2[i]);
                }
            }
        }
        if(v2.size()>n/2)
        {
            sort(v2.begin(),v2.end(),cmp2);
            for(int i=0;i<v2.size()-n/2;++i)
            {
                a[v2[i].t].t=3;
                v3.push_back(v2[i]);
            }
            if(v3.size()>n/2)
            {
                sort(v3.begin(),v3.end(),cmp3);
                for(int i=0;i<v3.size()-n/2;++i)
                {
                    a[v3[i].t].t=1;
                    v1.push_back(v3[i]);
                }
            }
        }
        if(v3.size()>n/2)
        {
            sort(v3.begin(),v3.end(),cmp3);
            for(int i=0;i<v3.size()-n/2;++i)
            {
                a[v3[i].t].t=1;
                v1.push_back(v3[i]);
            }
            if(v1.size()>n/2)
            {
               sort(v1.begin(),v1.end(),cmp1);
               for(int i=0;i<v1.size()-n/2;++i)
               {
                  a[v1[i].t].t=2;
                   v2.push_back(v1[i]);
               }
            }
        }
        int ans=0;
        int c1=0,c2=0,c3=0;
        for(int i=0;i<n;++i)
        {
            if(a[i].t==1)ans+=a[i].a,++c1;
            if(a[i].t==2)ans+=a[i].b,++c2;
            if(a[i].t==3)ans+=a[i].c,++c3;
        }
        cout<<ans<<endl;
    }
    return 0;
}