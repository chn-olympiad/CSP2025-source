#include<bits/stdc++.h>

using namespace std;

int posx;

struct node
{
    int pos;
    int cut;
};

bool comp(node a,node b)
{
    if(a.pos!=posx&&b.pos==posx)
    {
        return 0;
    }
    if(a.pos==posx&&b.pos==posx)
    {
        return a.cut<b.cut;
    }
    return 0;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int ans[t];
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int nn=n/2;
        node a[n];
        int coun[3]={0,0,0};
        int sum=0;
        int x,y,z,ma,mi;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y>>z;
            ma=max(x,max(y,z));
            mi=min(x,min(y,z));
            if(ma==x)
            {
                a[i].pos=1;
                coun[0]++;
            }
            if(ma==y)
            {
                a[i].pos=2;
                coun[1]++;
            }
            if(ma==z)
            {
                a[i].pos=3;
                coun[2]++;
            }
            sum=sum+ma;
            a[i].cut=2*ma+mi-x-y-z;
        }
        int over=max(coun[0],max(coun[1],coun[2]));
        if(over<=nn)
        {
            ans[i]=sum;
        }

        else
        {
            if(over==coun[0])
            {
                posx=1;
            }
            if(over==coun[1])
            {
                posx=2;
            }
            if(over==coun[2])
            {
                posx=3;
            }
            sort(a,a+n,comp);
            int cha=over-nn;
            for(int i=0;i<cha;i++)
            {
                sum=sum-a[i].cut;
            }
            ans[i]=sum;
        }
    }
    for(int i=0;i<t;i++)
    {
        cout<<ans[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
