#include<bits/stdc++.h>
using namespace std;
int n,t;
struct stu{
int a1,a2,a3,maxa;
}a[100005];
bool flag=0;
int sum,cnt1,cnt2,cnt3,ta[25003],m;
bool cmp(int i,int j)
{
    return i>j;//fuck CCF
}
void f1(int x){
    int z=0;
    for(int j=0;j<x;j++)
    {
        ta[z]=a[j].a1;
        z++;
    }
    sort(ta,ta+z,cmp);
    for(int j=0;j<25000;j++)
        sum+=ta[j];
    cout<<sum;
    return ;
}
void f2()
{
    for(int j=0;j<n;j++)
    {
        if(a[j].a1>a[j].a2 && a[j].a1>a[j].a3)
            a[j].maxa=a[j].a1;
        if(a[j].a2>a[j].a1 && a[j].a2>a[j].a3)
            a[j].maxa=a[j].a2;
        if(a[j].a3>a[j].a2 && a[j].a3>a[j].a1)
            a[j].maxa=a[j].a3;
        sum+=a[j].maxa;
    }
    cout<<sum;
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
cin>>t;
for(int i=0;i<t;i++)
{
    cin>>n;
    for(int j=0;j<n;j++)
    {
    cin>>a[i].a1>>a[i].a2>>a[i].a3;
    if(a[i].a2==0 && a[i].a3==0)
        flag=1;
    }
    if(flag)
        f1(n);
    else
        f2();

}
    fclose(stdin);
    fclose(stdout);
return 0;

}

