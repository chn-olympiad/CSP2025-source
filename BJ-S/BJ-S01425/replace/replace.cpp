#include<bits/stdc++.h>
using namespace std;
struct num
{
    int a1,a2,a3,c,cha1,cha2,cha3,chap1,chap2,chap3;
}a[100050];
int n,n1,n2,n3,sum,chu[10];
bool cmp1(num e,num f)
{
    return e.cha1<f.cha1;
}
bool cmp2(num e,num f)
{
    return e.cha2<f.cha2;
}
bool cmp3(num e,num f)
{
    return e.cha3<f.cha3;
}
void tiao1(int k)
{
    sort(a+1,a+n+1,cmp1);
    int tiaon=1,y=1;
    //for(int y=1;y<=k;y++)
    while(tiaon<=k)
    {
        if(a[y].c==1)
        {
            sum-=a[y].cha1;
            tiaon++;
            //a[y].c=(f^3);
        }
        y++;
    }
}
void tiao2(int k)
{
    sort(a+1,a+n+1,cmp2);
    int tiaon=1,y=1;
    //for(int y=1;y<=k;y++)
    while(tiaon<=k)
    {
        if(a[y].c==2)
        {
            sum-=a[y].cha1;
            tiaon++;
            //a[y].c=(f^3);
        }
        y++;
    }
}
void tiao3(int k)
{
    sort(a+1,a+n+1,cmp3);
    int tiaon=1,y=1;
    //for(int y=1;y<=k;y++)
    while(tiaon<=k)
    {
        if(a[y].c==3)
        {
            sum-=a[y].cha1;
            tiaon++;
            //a[y].c=(f^3);
        }
        y++;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,chal1,chal2,chal3;
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
            chal1=max(a[j].a1-a[j].a2,a[j].a2-a[j].a1);
            chal2=max(a[j].a1-a[j].a3,a[j].a3-a[j].a1);
            chal3=max(a[j].a2-a[j].a3,a[j].a3-a[j].a2);
//            if(chal1<chal2)
//            {
//                a[j].cha1=chal1;
//                a[j].chap1=1;
//            }
//            else
//            {
//                a[j].cha1=chal2;
//                a[j].chap1=2;
//            }
//            if(chal1<chal3)
//            {
//                a[j].cha1=chal1;
//                a[j].chap2=1;
//            }
//            else
//            {
//                a[j].cha1=chal3;
//                a[j].chap2=3;
//            }
//            if(chal2<chal3)
//            {
//                a[j].cha3=chal2;
//                a[j].chap3=1;
//            }
//            else
//            {
//                a[j].cha3=chal3;
//                a[j].chap3=2;
//            }
            a[j].cha1=min(chal1,chal2);
            a[j].cha2=min(chal1,chal3);
            a[j].cha3=min(chal2,chal3);
        }
        if(n1>(n/2))
        {
            tiao1(n1-(n/2));
            //cout<<"*"<<n1-(n/2)<<endl;
        }
        else if(n2>(n/2))
        {
            tiao2(n2-(n/2));
            //cout<<"*"<<n2-(n/2)<<endl;
        }
        else if(n3>(n/2))
        {
            tiao3(n3-(n/2));
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
