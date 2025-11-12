#include<bits/stdc++.h>
using namespace std;
struct people
{
public:
long long int d1,d2,d3;
};
int c[3];
long long int like(int d,people b)
    {
long long int a[3];
        a[0]=b.d1;
        a[1]=b.d2;
        a[2]=b.d3;
        sort(a,a+3);
        return a[d-1];
    }
    int * like0(people b)
    {
        if(b.d1>=b.d2&&b.d2>=b.d3)
        {
            c[0]=1;
            c[1]=2;
            c[3]=3;
        }
        if(b.d1>=b.d3&&b.d3>=b.d2)
        {
            c[0]=1;
            c[1]=3;
            c[3]=2;
        }
        if(b.d2>=b.d1&&b.d1>=b.d3)
        {
            c[0]=2;
            c[1]=1;
            c[3]=3;
        }
        if(b.d2>=b.d3&&b.d3>=b.d1)
        {
            c[0]=2;
            c[1]=3;
            c[3]=1;
        }
        if(b.d3>=b.d2&&b.d2>=b.d1)
        {
            c[0]=3;
            c[1]=2;
            c[3]=1;
        }
        if(b.d3>=b.d1&&b.d1>=b.d2)
        {
            c[0]=3;
            c[1]=1;
            c[3]=2;
        }
        return c;
    }
bool com(people a,people b)
{
    long long e,f;
    e=max(a.d1,max(a.d2,a.d3));
    f=max(b.d1,max(b.d2,b.d3));
    return max(e-a.d1,max(e-a.d2,e-a.d3))>max(f-b.d1,max(f-b.d2,f-b.d3));}
bool com1(people a,people b)
{
    return max(a.d2,a.d3)>max(b.d2,b.d3);
}
bool com2(people a,people b)
{
    return max(a.d1,a.d3)>(b.d1,b.d3);
}
bool com3(people a,people b)
{
    return max(a.d1,a.d2)>max(b.d1,b.d2);
}
int main(void)
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long int t,n;
    people a[100000];
    cin>>t;
    for(long long int k=0;k<t;k++)
    {
         long long int a1=0,a2=0,a3=0,s=0;
        cin>>n;
        for( long long int i=0;i<n;i++)
        {
            cin>>a[i].d1>>a[i].d2>>a[i].d3;
        }
        sort(a,a+n,com);
        for( long long int j=0;j<n;j++)
        {
            int * p;
            p=like0(a[j]);
            for(int i=0;i<3;i++)
            {
            if(*(p+i)==1&&a1!=n/2)
            {
                a1++;
                s+=a[j].d1;
                break;
            }
            if(*(p+i)==2&&a2!=n/2)
            {
                a2++;
                s+=a[j].d2;
                break;
            }
            if(*(p+i)==3&&a3!=n/2)
            {
                a3++;
                s+=a[j].d3;
                break;
            }
            }
            if(a1==n/2)
            {
                sort(a+j+1,a+n,com1);
            }
            if(a2==n/2)
            {
                sort(a+j+1,a+n,com2);
            }
            if(a3==n/2)
            {
                sort(a+j+1,a+n,com3);
            }
        }
            cout<<s<<endl;
    }
    return 0;
}
