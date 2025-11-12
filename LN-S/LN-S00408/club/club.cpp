#include <bits/stdc++.h>

using namespace std;
int T,a[100001][4],i,j,n,k[1001][501][500];
int J()
{
    int i,j,q,x,ans=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=min(i,n/2);j++)
        {
            for(q=max(i-n/2-j,0);q<=min(i-j,n/2);q++)
            {
                for(x=1;x<=3;x++)
                {
                    if(x==1)
                    {
                        if(j<1)
                        continue;
                        k[i][j][q]=max(k[i-1][j-1][q]+a[i][x],k[i][j][q]);
                    }
                    if(x==2)
                    {
                        if(q<1)
                        continue;
                         k[i][j][q]=max(k[i-1][j][q-1]+a[i][x],k[i][j][q]);
                    }
                    if(x==3)
                    {if(i-j-q<1)
                        continue;
                         k[i][j][q]=max(k[i-1][j][q]+a[i][x],k[i][j][q]);}

                }
            }
        }
    }


        for(j=0;j<=n/2;j++)
        {
            for(q=n/2-j;q<=n/2;q++)
            {
                ans=max(ans,k[n][j][q]);
            }
        }
        return ans;

}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        cout<<J()<<endl;
        memset(a,0,sizeof(a));
        memset(k,0,sizeof(k));
        n=0;
        T--;
    }
    return 0;
}
