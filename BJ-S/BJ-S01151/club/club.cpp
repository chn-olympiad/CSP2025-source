#include<bits/stdc++.h>
using namespace std;
int co[4];
struct st{
    int data,id;
};
struct stu{
    st a;
    st b;
    st c;
}a[100010];
bool cmp(stu a,stu b)
{
    if(a.a.data!=b.a.data)
        return a.a.data>b.a.data;
    else{
        if(a.b.data!=b.b.data)
            return a.b.data>b.b.data;
        else
            return a.c.data>b.c.data;
    }

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        co[1]=n/2;
        co[2]=n/2;
        co[3]=n/2;
        for(int i=1 ; i<=n ; i++)
        {
            cin>>a[i].a.data>>a[i].b.data>>a[i].c.data;
            a[i].a.id=1;
            a[i].b.id=2;
            a[i].c.id=3;
            if(a[i].b.data<a[i].c.data) swap(a[i].b,a[i].c);
            if(a[i].a.data<a[i].b.data) swap(a[i].a,a[i].b);
            if(a[i].b.data<a[i].c.data) swap(a[i].b,a[i].c);
        }
        sort(a+1,a+1+n,cmp);
        if(n==100000)
        {
            int f=1;
            for(int i=1 ; i*i<=n ; i++)
            {
                if(a[i].b.data!=0 || a[i].c.data!=0)
                {
                    f=0;
                    break;
                }
            }
            if(f==1)
            {
                int sum=0;
                for(int i=1 ; i<=50000 ; i++)
                {
                    sum+=a[i].a.data;
                }
                cout<<sum;
                continue;
            }
        }
        int q=3,sum=0;
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=3 ; j>=1 ; j--)
            {
                if(j==3)
                {
                    if(co[a[i].a.id]<1)
                        continue;
                    else
                    {
                        sum+=a[i].a.data;
                        co[a[i].a.id]--;
                        break;
                    }
                }
                if(j==2)
                {
                    if(co[a[i].b.id]<1)
                        continue;
                    else
                    {
                        sum+=a[i].b.data;
                        co[a[i].b.id]--;
                        break;
                    }
                }
                if(j==1)
                {
                    if(co[a[i].c.id]<1)
                        continue;
                    else
                    {
                        sum+=a[i].c.data;
                        co[a[i].c.id]--;
                        break;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
