#include<bits/stdc++.h>
using namespace std;
int shu[1000],s[1000][1000];
int m,mx=0,p1,q1=0,r1=0,cnt=0;
bool p=true,q=true,r=true;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        cin>>m;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<3;j++)
                cin>>s[i][j];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                {
                    if(p==false&&q==false&&r==false)
                        break;
                    if(p!=false&&q!=false&&r!=false)
                    {
                        s[i][j]=max(max(s[i-1][j+1]+s[i][j],s[i-1][j]+s[i][j]),s[i-1][j+2]+s[i][j]);
                    }
                    else if(p==false&&q==true&&r==true)
                    {
                        s[i][j]=max(s[i-1][j+1]+s[i][j],s[i-1][j+2]+s[i][j]);
                    }
                    else if(p!=false&&q==false&&r!=false)
                    {
                        s[i][j]=max(s[i-1][j]+s[i][j],s[i-1][j+2]+s[i][j]);
                    }
                    else if(p!=false&&q!=false&&r==false)
                    {
                        s[i][j]=max(s[i-1][j+1]+s[i][j],s[i-1][j]+s[i][j]);
                    }
                    else if(p==false&&q==false&&r!=false)
                    {
                        s[i][j]=s[i-1][j+2]+s[i][j];
                    }
                    else if(p==false&&q!=false&&r==false)
                    {
                        s[i][j]=s[i-1][j+1]+s[i][j];
                    }
                    else if(p!=false&&q==false&&r==false)
                    {
                        s[i][j]=s[i-1][j]+s[i][j];
                    }
                    if(s[i][j]==s[i-1][j+1]+s[i][j])
                    {
                        q1++;
                        if(q1=m/2) q=false;
                        break;
                    }
                    if(s[i][j]==s[i-1][j]+s[i][j])
                    {
                        p1++;
                        if(p1=m/2) p=false;
                        break;
                    }
                    if(s[i][j]==s[i-1][j+2]+s[i][j])
                    {
                        r1++;
                        if(r1=m/2) r=false;
                        break;
                    }
                }
                if(j==1)
                {
                    if(p==false&&q==false&&r==false)
                        break;
                    if(p!=false&&q!=false&&r!=false)
                    {
                        s[i][j]=max(max(s[i-1][j+1]+s[i][j],s[i-1][j]+s[i][j]),s[i-1][j-1]+s[i][j]);
                    }
                    else if(p==false&&q==true&&r==true)
                    {
                        s[i][j]=max(s[i-1][j+1]+s[i][j],s[i-1][j]+s[i][j]);
                    }
                    else if(p!=false&&q==false&&r!=false)
                    {
                        s[i][j]=max(s[i-1][j+1]+s[i][j],s[i-1][j-1]+s[i][j]);
                    }
                    else if(p!=false&&q!=false&&r==false)
                    {
                        s[i][j]=max(s[i-1][j]+s[i][j],s[i-1][j]+s[i][j]);
                    }
                    else if(p==false&&q==false&&r!=false)
                    {
                        s[i][j]=s[i-1][j+1]+s[i][j];
                    }
                    else if(p==false&&q!=false&&r==false)
                    {
                        s[i][j]=s[i-1][j]+s[i][j];
                    }
                    else if(p!=false&&q==false&&r==false)
                    {
                        s[i][j]=s[i-1][j-1]+s[i][j];
                    }
                    if(s[i][j]==s[i-1][j+1]+s[i][j])
                    {
                        q1++;
                        if(q1=m/2) q=false;
                        break;
                    }
                    if(s[i][j]==s[i-1][j]+s[i][j])
                    {
                        q1++;
                        if(q1=m/2) q=false;
                        break;
                    }
                    if(s[i][j]==s[i-1][j-1]+s[i][j])
                    {
                        p1++;
                        if(p1=m/2) p=false;
                        break;
                    }
                    if(s[i][j]==s[i-1][j+1]+s[i][j])
                    {
                        r1++;
                        if(r1=m/2) r=false;
                        break;
                    }
                }
                if(j==2)
                {
                    if(p==false&&q==false&&r==false)
                        break;
                    if(p!=false&&q!=false&&r!=false)
                    {
                        s[i][j]=max(max(s[i-1][j-1]+s[i][j],s[i-1][j]+s[i][j]),s[i-1][j-2]+s[i][j]);
                    }
                    else if(p==false&&q==true&&r==true)
                    {
                        s[i][j]=max(s[i-1][j+1]+s[i][j],s[i-1][j]+s[i][j]);
                    }
                    else if(p!=false&&q==false&&r!=false)
                    {
                        s[i][j]=max(s[i-1][j]+s[i][j],s[i-1][j-2]+s[i][j]);
                    }
                    else if(p!=false&&q!=false&&r==false)
                    {
                        s[i][j]=max(s[i-1][j-2]+s[i][j],s[i-1][j-1]+s[i][j]);
                    }
                    else if(p==false&&q==false&&r!=false)
                    {
                        s[i][j]=s[i-1][j]+s[i][j];
                    }
                    else if(p==false&&q!=false&&r==false)
                    {
                        s[i][j]=s[i-1][j-1]+s[i][j];
                    }
                    else if(p!=false&&q==false&&r==false)
                    {
                        s[i][j]=s[i-2][j]+s[i][j];

                    }
                     if(s[i][j]==s[i-1][j+1]+s[i][j])
                    {
                        q1++;
                        if(q1=m/2) q=false;
                        break;
                    }
                    if(s[i][j]==s[i-1][j-1]+s[i][j])
                    {
                        q1++;
                        if(q1=m/2) q=false;
                    }
                    if(s[i][j]==s[i-1][j-2]+s[i][j])
                    {
                        p1++;
                        if(p1=m/2) p=false;
                        break;
                    }
                    if(s[i][j]==s[i-1][j]+s[i][j])
                    {
                        r1++;
                        if(r1=m/2) r=false;
                        break;
                    }
                }
            }
        }
                shu[cnt]=max(max(s[m-1][0],s[m-1][1]),s[m-1][2]);
                cnt++;
    }
    for(int i=0;i<cnt;i++)
    {
        cout<<shu[i]<<endl;
    }
    return 0;
}
