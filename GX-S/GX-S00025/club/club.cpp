#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
struct Y{
    int number;
    char id;
}maxi[200005],maxi2[200005],maxi3[200005];
int maxn(int x,int y,int z)
{
    if(max(x,y)==x)
    {
        return max(x,z);
    }
    else if(max(x,y)==y)
    {
        return max(y,z);
    }
}
int minn(int x,int y,int z)
{
    if(min(x,y)==x)
    {
        return min(x,z);
    }
    else if(min(x,y)==y)
    {
        return min(y,z);
    }
}
int midn(int x,int y,int z)
{
    return x+y+z-maxn(x,y,z)-minn(x,y,z);
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        int a[100005]={0},b[100005]={0},c[100005]={0},n,sum=0,sum1,sum2,sum3,cs[100]={0};
        cin>>n;
        cs['a']=n/2;
        cs['b']=n/2;
        cs['c']=n/2;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
        }
        for(int j=1;j<=n;j++)
        {
            maxi[j].number=maxn(a[j],b[j],c[j]);//number1 shanc
            if(maxn(a[j],b[j],c[j])==a[j])
            {
                maxi[j].id='a';
            }
            else if(maxn(a[j],b[j],c[j])==b[j])
            {
                maxi[j].id='b';
            }
            else if(maxn(a[j],b[j],c[j])==c[j])
            {
                maxi[j].id='c';
            }
            maxi2[j].number=midn(a[j],b[j],c[j]);//numbei2 shanc
            if(midn(a[j],b[j],c[j])==a[j])
            {
                maxi2[j].id='a';
            }
            else if(midn(a[j],b[j],c[j])==b[j])
            {
                maxi2[j].id='b';
            }
            else if(midn(a[j],b[j],c[j])==c[j])
            {
                maxi2[j].id='c';
            }
            maxi3[j].number=minn(a[j],b[j],c[j]);//number3 shanc
            if(minn(a[j],b[j],c[j])==a[j])
            {
                maxi3[j].id='a';
            }
            else if(minn(a[j],b[j],c[j])==b[j])
            {
                maxi3[j].id='b';
            }
            else if(minn(a[j],b[j],c[j])==c[j])
            {
                maxi3[j].id='c';
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=j;k<=n;k++)
            {
                if(maxi[j].number<maxi[k].number)
                {
                    swap(maxi[j].number,maxi[k].number);
                    swap(maxi[j].id,maxi[k].id);
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=j;k<=n;k++)
            {
                if(maxi2[j].number<maxi2[k].number)
                {
                    swap(maxi2[j].number,maxi2[k].number);
                    swap(maxi2[j].id,maxi2[k].id);
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            for(int k=j;k<=n;k++)
            {
                if(maxi3[j].number<maxi3[k].number)
                {
                    swap(maxi3[j].number,maxi3[k].number);
                    swap(maxi3[j].id,maxi3[k].id);
                }
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(cs[maxi[j].id]>0)
            {
                sum+=maxi[j].number;
                cs[maxi[j].id]--;
            }
            else if(cs[maxi2[j].id]>0)
            {
                sum+=maxi2[j].number;
                cs[maxi2[j].id]--;
            }
            else if(cs[maxi3[j].id]>0)
            {
                sum+=maxi3[j].number;
                cs[maxi3[j].id]--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
