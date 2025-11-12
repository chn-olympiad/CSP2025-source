#include <iostream>
using namespace std;
int m,n;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >>n>>m;
    int everyone=n*m;
    int s[everyone+2];
    for(int i=1;i<=everyone;i++)//输入
    {
        cin >>s[i];
    }
    int s_bak[everyone+2];
    for(int i=1;i<=everyone;i++)
    {
        s_bak[i]=s[i];
    }
    int temp;
    for(int k=0;k<=everyone;k++)//冒泡
    {
        for(int h=0;h<everyone;h++)
        {
            if(s[h]<s[h+1])
            {
                temp=s[h];
                s[h]=s[h+1];
                s[h+1]=temp;
            }
        }
    }
    int iuse=0;//排名
    for(int i=1;i<=everyone;i++)//排名查找
    {
        if(s_bak[1]==s[i-1])
        {
            iuse=i;
            break;
        }
    }
    int over[2]={0,0};
    int jsq=0;
    for(int x=1;x<=n;x++)
    {
        if(x%2==0)
        {
            for(int y=m;y>=1;y--)
            {
                jsq++;
                if(jsq==iuse)
                {
                    over[0]=x;
                    over[1]=y;
                    break;
                }
            }
        }
        else
        {
            for(int y=1;y<=m;y++)
            {
                jsq++;
                if(jsq==iuse)
                {
                    over[0]=x;
                    over[1]=y;
                    break;
                }
            }
        }
    }
    cout <<over[0]<<" "<<over[1];
    fclose(stdin);
    fclose(stdout);
    return 0;
}