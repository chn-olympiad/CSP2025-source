#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
    int n,m;
    int o=0;
    cin>>n>>m;
    int seats[n][m];
    int s=n*m;
    int R;
    cin>>R;
    int score[s+1];
    score[1]==R;
    for(int i=2;i<=s;i++)
    {
        cin>>score[i];
        if(score[i]<score[i+1])
        {
            swap(score[i],score[i+1]);
        }
    }
    for(int j=1;j<m;j++)
    {
       if(j%2!=0)
       {
           for(int l=1;l<=m;l++)
           {
               seats[j][l]=score[o++];
           }
       }
       else
       {
           for(int x=m;x>=1;x--)
           {
               seats[j][x]=score[o++];
           }
       }

}
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)
    {
        if(seats[m][n]==R)
        {
            cout<<n<<m;
        }
    }
    }
return 0;
}
