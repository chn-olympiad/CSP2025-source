#include<bits/stdc++.h>
using namespace std;
int t,n;
int l[3][5000]={0},ln[3]={0};
struct member
{
    int l[3];
};
int fav(member m)
{
    int M=0;
    for(int i=0;i<3;i++)
    {
        if(m.l[i]>m.l[M])
            M=i;
    }
    return M;
}
member m[5000];
bool cmp0(int a,int b)
{
    return m[a].l[0]>m[b].l[0];
}
bool cmp1(int a,int b)
{
    return m[a].l[1]>m[b].l[1];
}
bool cmp2(int a,int b)
{
    return m[a].l[2]>m[b].l[2];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ln[0]=0;
        ln[1]=0;
        ln[2]=0;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>m[j].l[0]>>m[j].l[1]>>m[j].l[2];
            l[fav(m[j])][ln[fav(m[j])]++]=j;
        }
        sort(l[0],l[0]+ln[0],cmp0);
        sort(l[1],l[1]+ln[1],cmp1);
        sort(l[2],l[2]+ln[2],cmp2);
        while(ln[0]>n/2)
        {
            if(m[l[0][ln[0]-1]].l[1]>m[l[0][ln[0]-1]].l[2])
            {
                l[1][ln[1]++]=l[0][ln[0]-1];
                ln[0]--;
            }
            else
            {
                l[2][ln[2]++]=l[0][ln[0]-1];
                ln[0]--;
            }
        }
        while(ln[1]>n/2)
        {
            if(m[l[1][ln[1]-1]].l[0]>m[l[1][ln[1]-1]].l[2])
            {
                l[0][ln[0]++]=l[1][ln[1]-1];
                ln[1]--;
            }
            else
            {
                l[2][ln[2]++]=l[1][ln[1]-1];
                ln[1]--;
            }
        }
        while(ln[2]>n/2)
        {
            if(m[l[2][ln[2]-1]].l[0]>m[l[2][ln[2]-1]].l[1])
            {
                l[0][ln[0]++]=l[2][ln[2]-1];
                ln[2]--;
            }
            else
            {
                l[1][ln[1]++]=l[2][ln[2]-1];
                ln[2]--;
            }
        }
        int sum=0;
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<ln[j];k++)
                sum+=m[l[j][k]].l[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
