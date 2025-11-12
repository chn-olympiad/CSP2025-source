#include<bits/stdc++.h>
using namespace std;
struct person{
    int a[3],pp;
    int maxx,next;
};
person p[100002];
void pre(person k)
{
    k.maxx=max(max(k.a[0],k.a[1]),k.a[2]);
    if(k.maxx==k.a[0]){
        k.pp=0;
        k.next=max(k.a[1],k.a[2])-k.a[0];
    }
    else if(k.maxx==k.a[1]){
        k.pp=1;
        k.next=max(k.a[0],k.a[2])-k.a[1];
    }
    else{
        k.pp=2;
        k.next=max(k.a[0],k.a[1])-k.a[2];
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,sum=0;
        int num[3]={0};
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>p[j].a[0]>>p[j].a[1]>>p[j].a[2];
                p[j].maxx=max(max(p[j].a[0],p[j].a[1]),p[j].a[2]);
    if(p[j].maxx==p[j].a[0]){
        p[j].pp=0;
        p[j].next=max(p[j].a[1],p[j].a[2])-p[j].a[0];
    }
    else if(p[j].maxx==p[j].a[1]){
        p[j].pp=1;
        p[j].next=max(p[j].a[0],p[j].a[2])-p[j].a[1];
    }
    else{
        p[j].pp=2;
        p[j].next=max(p[j].a[0],p[j].a[1])-p[j].a[2];
    }
            sum+=p[j].maxx;
            num[p[j].pp]++;
        }
        if(num[0]>n/2||num[1]>n/2||num[2]>n/2)
        {
            int unwill;
            if(num[0]>n/2) unwill=0;
            else if(num[1]>n/2) unwill=1;
            else unwill=2;
            int out=num[unwill]-n/2;
            for(int j=0;j<out;j++)
            {
                int minn=INT_MIN,z;
                for(int k=0;k<n;k++)
                {
                    if(p[k].pp==unwill)
                    {
                         if(minn<p[k].next){
                            minn=p[k].next;
                            z=k;
                         }
                    }
                }
                p[z].pp=9;
                sum+=minn;
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
