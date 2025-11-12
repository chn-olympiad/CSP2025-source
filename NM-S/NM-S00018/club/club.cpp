#include <bits/stdc++.h>
using namespace std;
int m,n;
int a2[3]={0};
int a1[100001]={0};
int len=0;
struct ddd
{
    int x1;
    int x2;
    int x3;
    int maX=0;
    int mid=0;
    int la=0;
};

bool sf(int n1,int n2)
{
    if(n1>n2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int paixu(int n,ddd a[])
{
    ddd d;
    for(int i=0;i<n;i++)
    {
        if(a[i].x1>=a[i].maX)
        {
            a[i].maX=a[i].x1;
        }
        if(a[i].x2>=a[i].maX)
        {
            a[i].maX=a[i].x2;
        }
        if(a[i].x3>=a[i].maX)
        {
            a[i].maX=a[i].x3;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int y=i+1;y<n;y++)
        {
            if(a[i].maX<=a[y].maX)
            {
                d=a[y];
                a[y]=a[i];
                a[i]=d;
            }
        }
    }
}

int ccc(int n,ddd a[],int len)
{
    len=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].x1>=a[i].x2&&a[i].x1>=a[i].x3)
        {
            a2[0]++;
            len+=a[i].x1;
            if(a[i].x2>=a[i].x3)
            {
                a[i].mid=a[i].x2;
                a[i].la=a[i].x3;
                if(sf(a2[0],n/2))
                {
                    if(sf(a2[1],n/2))
                    {
                        len-=a[i].x1;
                        len+=a[i].la;
                        a2[0]--;
                        a2[2]++;
                        continue;
                    }
                    else
                    {
                        len-=a[i].x1;
                        len+=a[i].mid;
                        a2[0]--;
                        a2[1]++;
                        continue;
                    }
                }
            }
            else
            {
                a[i].mid=a[i].x3;
                a[i].la=a[i].x2;
                if(sf(a2[0],n/2))
                {
                    if(sf(a2[2],n/2))
                    {

                        len-=a[i].x1;
                        len+=a[i].la;
                        a2[0]--;
                        a2[2]++;
                        continue;

                    }
                    else
                    {
                        len-=a[i].x1;
                        len+=a[i].mid;
                        a2[0]--;
                        a2[1]++;
                        continue;
                    }

                }
            }
        }
        else
        {
            if(a[i].x1>=a[i].x2&&a[i].x1<=a[i].x3)
            {
                a2[2]++;
                len+=a[i].x3;
                a[i].maX=a[i].x3;
                a[i].mid=a[i].x1;
                a[i].la=a[i].x2;
                if(sf(a2[2],n/2))
                {
                    if(sf(a2[0],n/2))
                    {
                        len-=a[i].x3;
                        len+=a[i].la;
                        a2[2]--;
                        a2[1]++;
                    }
                    else
                    {
                        len-=a[i].x3;
                        len+=a[i].mid;
                        a2[2]--;
                        a2[0]++;
                    }
                    continue;
                }
            }
            else
            {
                if(a[i].x1>=a[i].x3&&a[i].x2>=a[i].x1)
                {
                    a2[1]++;
                    len+=a[i].x2;
                    a[i].maX=a[i].x2;
                    a[i].mid=a[i].x1;
                    a[i].la=a[i].x3;
                    if(sf(a2[1],n/2))
                    {
                        if(sf(a2[0],n/2))
                        {
                            len-=a[i].x2;
                            len+=a[i].la;
                            a2[1]--;
                            a2[2]++;
                            continue;
                        }
                        else
                        {
                            len-=a[i].x2;
                            len+=a[i].mid;
                            a2[1]--;
                            a2[0]++;
                            continue;
                        }
                        continue;
                    }
                }
                else
                {
                    a[i].la=a[i].x1;
                    if(a[i].x3>=a[i].x2&&a[i].x2>=a[i].x1)
                    {
                        a2[2]++;
                        a[i].maX=a[i].x3;
                        a[i].mid=a[i].x2;
                        a[i].la=a[i].x1;
                        len+=a[i].x3;
                        if(sf(a2[2],n/2))
                        {
                            if(sf(a2[1],n/2))
                            {
                                len-=a[i].x3;
                                len+=a[i].la;
                                a2[2]--;
                                a2[0]++;
                                continue;
                            }
                            else
                            {
                                len-=a[i].x3;
                                len+=a[i].mid;
                                a2[2]--;
                                a2[1]++;
                                continue;
                            }
                        }


                    }
                    else
                    {
                        a2[1]++;
                        a[i].maX=a[i].x2;
                        a[i].mid=a[i].x3;
                        a[i].la=a[i].x1;
                        len+=a[i].x2;
                        if(sf(a2[1],n/2))
                        {
                            if(sf(a2[2],n/2))
                            {
                                len-=a[i].x2;
                                len+=a[i].la;
                                a2[1]--;
                                a2[0]++;
                                continue;
                            }
                            else
                            {
                                len-=a[i].x3;
                                len+=a[i].mid;
                                a2[1]--;
                                a2[2]++;
                                continue;
                            }
                        }

                    }
                }
            }
        }

    }

    return len;
}

int main()
{
    freopen("club1.in","r",stdin);
    freopen("club.out","w",stdout);
    ddd a[100001]={0};
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>n;
        for(int y=0;y<n;y++)
        {
            cin>>a[y].x1;
            cin>>a[y].x2;
            cin>>a[y].x3;
        }
        paixu(n,a);
        a1[i]=ccc(n,a,len);
        a2[0]=0;
        a2[1]=0;
        a2[2]=0;
        for(int y=0;y<n;y++)
        {
            a[y].maX=0;
            a[y].mid=0;
            a[y].la=0;
        }
    }
    for(int i=0;i<m;i++)
    {

        cout<<a1[i]<<endl;
    }
    return 0;
}
