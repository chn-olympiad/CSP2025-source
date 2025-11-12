#include<bits/stdc++.h>
using namespace std;
int m,n[10000],k,a[10000][10000],ans_1,ans_2,he,Max;
int digui(int step,int p,int g)
{
    if(step == g){
        ans_1+=1;
        return 0;
    }
    for(int i = p;i <= m;i++)
    {
        a[ans_1][step] = i;
        digui(step+1,i+1,g);
    }
    return 0;
}
int main()
{
    // freopen("polygon.in","r",stdin);
    // freopen("polygon,out","w",stdout);
    cin>>m;
    for(int i = 1;i <= m;i++)
    {
        cin>>n[i];
    }
    for(int i = 3;i <= m;i++)
    {
        digui(0,1,i);
    }
    for(int i = 0;i < ans_1;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(a[i][j] == 0)
            {
                a[i][j] = a[i-1][j];
            }
        }
    }
    for(int i = 0;i < ans_1;i++)
    {
        for(int j = 0;j < m;j++)
        {
            he += n[a[i][j]];
                if(n[a[i][j]] >= Max)
                {
                    Max = n[a[i][j]];
                }
        }
        if(he > Max*2)
        {
            ans_2+=1;
        }
        he = 0;
        Max = 0;
    }
    cout<<ans_2;
}