#include<bits/stdc++.h>
using namespace std;
#define ull  long long
int main()
{
  freopen("club.in","r",stdin);
  freopen("club.out","w",stdout);
    int tmp;
    cin>>tmp;
    ull num=0,sum=0,kum=0;
    ull we=0,wr=0,wt=0;
    for(int h=0;h<tmp;h++)
    {
        ull n;
        cin>>n;
        ull ui[6][n+3]={0};
        for(int i=1;i<=n;i++)
        {
            cin>>we>>wr>>wt;
            num+=we;
            ui[0][i]=we;
            ui[1][i]=wr-we;
            ui[2][i]=wt-we;
            if(ui[1][i]>=ui[2][i])
            ui[3][i]=i;
            ui[4][i]=max(ui[1][i],ui[2][i]);
        }



    for(int i=n;i>=1;i--)
    {

        for(int t=2;t<=i;t++)
        {

            if(ui[0][t]>ui[0][t-1])
            {
                swap(ui[1][t],ui[1][t-1]);
                swap(ui[0][t],ui[0][t-1]);
                swap(ui[2][t],ui[2][t-1]);
                swap(ui[4][t],ui[4][t-1]);
            }
            else if(ui[0][t]==ui[0][t-1])
            {
                if(ui[4][t]>ui[4][t-1])
                {
                swap(ui[1][t],ui[1][t-1]);
                swap(ui[0][t],ui[0][t-1]);
                swap(ui[2][t],ui[2][t-1]);
                swap(ui[4][t],ui[4][t-1]);
                }
            }
        }
    }
    for(int i=n;i>=(n/2)+1;i--)
    {

        for(int t=(n/2)+1;t<i;t++)
        {

            if(ui[0][t]>ui[0][t-1])
            {
                swap(ui[1][t],ui[1][t-1]);
                swap(ui[0][t],ui[0][t-1]);
                swap(ui[2][t],ui[2][t-1]);
                swap(ui[4][t],ui[4][t-1]);
            }
            else if(ui[0][t]==ui[0][t-1])
            {
                if(ui[4][t]>ui[4][t-1])
                {
                swap(ui[1][t],ui[1][t-1]);
                swap(ui[0][t],ui[0][t-1]);
                swap(ui[2][t],ui[2][t-1]);
                swap(ui[4][t],ui[4][t-1]);
                }
            }
        }
    }

       for(ull i=n;i>=(n/2)+1;i--)
       {
        num+=ui[4][i];
       }
       cout<<num;
   }

  fclose(stdin);
  fclose(stdout);
  return 0;
}
