#include<bits/stdc++.h>
using namespace std;
struct num
{
    int a1,a2,a3,c,cha1;
}a[100050];
int n,n1,n2,n3,sum,chu[10];
bool cmp(num e,num f)
{
    return e.cha1<f.cha1;
}
void tiao(int f,int k)
{
    sort(a+1,a+n+1,cmp);
    int tiaon=1,y=1;
    //for(int y=1;y<=k;y++)
    while(tiaon<=k)
    {
        if(a[y].c==f)
        {
            sum-=a[y].cha1;
            tiaon++;
            a[y].c=(f^3);
        }
        y++;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        n1=0;
        n2=0;
        n3=0;
        sum=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j].a1>>a[j].a2>>a[j].a3;
            if(a[j].a1>=a[j].a2&&a[j].a1>=a[j].a3)
            {
                a[j].c=1;
                n1++;
                sum+=a[j].a1;
            }
            else if(a[j].a2>=a[j].a1&&a[j].a2>=a[j].a3)
            {
                a[j].c=2;
                n2++;
                sum+=a[j].a2;
            }
            else if(a[j].a3>=a[j].a1&&a[j].a3>=a[j].a2)
            {
                a[j].c=3;
                n3++;
                sum+=a[j].a3;
            }
            a[j].cha1=max(a[j].a1-a[j].a2,a[j].a2-a[j].a1);
        }
        if(n1>(n/2))
        {
            tiao(1,n1-(n/2));
            //cout<<"*"<<n1-(n/2)<<endl;
        }
        else if(n2>(n/2))
        {
            tiao(2,n2-(n/2));
            //cout<<"*"<<n2-(n/2)<<endl;
        }
        chu[i]=sum;
    }
//    for(int j=1;j<=n;j++)
//    {
//        cout<<a[j].a1<<" "<<a[j].a2<<" "<<a[j].a3<<" "<<a[j].c<<" "<<endl;
//    }
//    int cntl=0;
//    for(int j=1;j<=n;j++)
//    {
//        if(a[j].c==2)
//        {
//            cntl++;
//        }
//    }
//    cout<<cntl<<endl;
    for(int i=0;i<t;i++)
    {
        cout<<chu[i]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
