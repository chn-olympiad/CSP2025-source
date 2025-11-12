#include<bits/stdc++.h>
using namespace std;
int n,q,tong[1005][1005];
string s1,s2,s3,s4;
struct node
{
    int a,b,len;
}stu1[100005],stu2[100005];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s1>>s2;
        int lena=s1.size();
        stu1[i].len=lena;
        for(int j=0;j<lena;j++)
        {
            if(s1[j]=='b')
            {
                stu1[i].a=j;
                break;
            }
        }
        for(int j=0;j<lena;j++)
        {
            if(s2[j]=='b')
            {
                stu1[i].b=j;
                break;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        cin>>s3>>s4;
        int lena=s3.size();
        stu2[i].len=lena;
        for(int j=0;j<lena;j++)
        {
            if(s3[j]=='b')
            {
                stu2[i].a=j;
                break;
            }
        }
        for(int j=0;j<lena;j++)
        {
            if(s4[j]=='b')
            {
                stu2[i].b=j;
                break;
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s=0;
        for(int j=1;j<=n;j++)
        {
            if(stu1[j].a<=stu2[i].a&&(stu1[j].len-stu1[j].b)<=(stu2[i].len-stu2[i].b)&&stu1[j].b-stu1[j].a==stu2[i].b-stu2[i].a)
            {
                s++;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
