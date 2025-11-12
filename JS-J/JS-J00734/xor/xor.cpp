#include<bits/stdc++.h>
using namespace std;
bool dt[500005][10];
int sl[500005];
long long sw[500005][2];
int memsw[500005][2][60];
int n;
bool chck(int d)
{
    for(int i=0;i<=9;i++)
    {
        if(dt[d][i]!=dt[0][i])
        {
            return 0;
        }
    }
    return 1;
}
void workout(int d,int f)
{
    for(int i=0;i<=9;i++)
    {
        if(dt[d][i]!=dt[f][i])
        {
            dt[d][i]=1;
        }
        else
        {
            dt[d][i]=0;
        }
    }
    return;
}
long long solving(int x,bool s,long long cnt)
{
    if(x>n)
    {
        return cnt;
    }

    if(sw[x][s]>cnt||(sw[x][s]!=0&&sw[x][s]==cnt))
    {
        return cnt;
    }
    else
    {
        sw[x][s]=cnt;
    }
    if((sl[x]!=0)&&s)
    {
        if(memsw[x][s][cnt])
        {
            return memsw[x][s][cnt];
        }
        if(cnt<=60)
        {
            memsw[x][s][cnt]=max(solving(sl[x]+1,1,cnt+1),solving(sl[x]+1,0,cnt+1));
        }
        return memsw[x][s][cnt];
    }
    return max(solving(x+1,1,cnt),solving(x+1,0,cnt));
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n;
    long long resle,sle;
    for(int i=0;i<=n;i++)
    {
        cin>>resle;
        sle=128;
        for(int j=9;j>=0;j--)
        {
            if(!resle)
            {
                break;
            }
            if(resle>=sle)
            {
                dt[i][j]=1;
                resle-=sle;
            }
            sle/=2;
        }
    }

    for(int i=1;i<=n;i++)
    {
        bool f=chck(i);
        if(f)
        {
            sl[i]=i;
            continue;
        }
        for(int j=i+1;j<=n;j++)
        {
            workout(i,j);
            bool f=chck(i);
            if(f)
            {
                sl[i]=j;
                break;
            }
        }
    }

    long long ans=solving(0,0,0);
    cout<<ans;
    return 0;
    //The King Of Violenting Searching!
}
