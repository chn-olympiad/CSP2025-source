#include <bits/stdc++.h>
using namespace std;
int suan();
void pop();
int n,a[10001][10];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,d[10]={0};
    cin>>t;
    for(int q=0;q<t;q++)
    {
        for(int g=0;g<=10000;g++)
        {
            for(int h=0;h<10;h++)
            {
                a[g][h]=0;
            }
        }
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            a[i][3]=a[i][0]+a[i][1]+a[i][2];
            a[i][4]=max(a[i][0],max(a[i][1],a[i][2]));
            if(a[i][4]==a[i][0]) a[i][5]=0;
            if(a[i][4]==a[i][1]) a[i][5]=1;
            if(a[i][4]==a[i][2]) a[i][5]=2;
            a[i][6]=min(a[i][0],min(a[i][1],a[i][2]));
            if(a[i][6]==a[i][0]) a[i][7]=0;
            if(a[i][6]==a[i][1]) a[i][7]=1;
            if(a[i][6]==a[i][2]) a[i][7]=2;
            a[i][8]=6-a[i][5]-a[i][7];
            if(a[i][8]==a[i][0]) a[i][9]=0;
            if(a[i][8]==a[i][1]) a[i][9]=1;
            if(a[i][8]==a[i][2]) a[i][9]=2;
        }
        d[q]=suan();
    }
    for(int i=0;i<t;i++)
    {
        cout<<d[i]<<endl;
    }
    return 0;
}
int suan()
{
    int add=0;
    int x[5]={0};
    int ren=n/2;
    pop();
    for(int i=0;i<n;i++)
    {
        if(x[a[i][5]]<ren)
        {
            x[a[i][5]]++;
            add+=a[i][4];
        }
        else if(x[a[i][9]]<ren)
        {
            x[a[i][9]]++;
            add+=a[i][8];
        }
        else
        {
            x[a[i][7]]++;
            add+=a[i][6];
        }
    }
    cout<<endl;
    return add;
}
void pop()
{
    int x;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j][3]<a[j+1][3])
            {
                x=a[j][0],a[j][0]=a[j+1][0],a[j+1][0]=x;
                x=a[j][1],a[j][1]=a[j+1][1],a[j+1][1]=x;
                x=a[j][2],a[j][2]=a[j+1][2],a[j+1][2]=x;
                x=a[j][3],a[j][3]=a[j+1][3],a[j+1][3]=x;
            }
        }
    }
}
