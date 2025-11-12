#include <bits/stdc++.h>
using namespace std;
int t;
struct stu
{
    int a;
    int b;
    int c;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m=0,temp;
        int t[6];
        int cnt=0;
        int ans=0;
        stu s[100005];
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>s[j].a>>s[j].b>>s[j].c;
        }
        if(n==2)
        {
            t[0]=s[0].a+s[1].b;
            t[1]=s[0].a+s[1].c;
            t[2]=s[0].b+s[1].c;
            t[3]=s[0].b+s[1].a;
            t[4]=s[0].c+s[1].a;
            t[5]=s[0].c+s[1].b;
            sort(t,t+6);
            cout<<t[5]<<endl;
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                for(int k=j;k<n;k++)
                {
                    if(s[j].a>s[k].a)
                    {
                        temp=s[j].a;
                        s[j].a=s[k].a;
                        s[k].a=temp;
                    }
                }
            }
            for(int j=n/2;j<n;j++)
            {
                ans+=s[j].a;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
