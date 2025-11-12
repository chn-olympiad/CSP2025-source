#include<bits/stdc++.h
using namespace std;
struct stu
{
    int st,nd,rd,s;
}a[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int c=0;c<t;c++)
    {
        int s1=0,s2=0,s3=0,sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].st>>a[i].nd>>a[i].rd;
            if(a[i].st>a[i].nd&&a[i].st>a[i].rd)
            {
                a[i].s=1;
                s1++
                sum+=a[i].st;
            }
            if(a[i].nd>a[i].st&&a[i].nd>a[i].rd)
            {
                a[i].s=2;
                s2++;
                sum+=a[i].nd;
            }
            else
            {
                a[i].s=3;
                s3++;
                sum+=a[i].rd;
            }
        }
        cout<<sum>>endl;
    }
}
