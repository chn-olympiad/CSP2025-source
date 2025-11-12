#include <bits/stdc++.h>
using namespace std;
int n,m,score[1000],iscr,inum,sih=1,sil=1;
int cmp(int x,int y)
{

    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        cin>>score[i];
    }
    iscr=score[1];
    sort(score+1,score+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(score[i]==iscr)
        {
            inum=i;
            break;
        }
    }
   int cinum=inum;
   while(cinum>n)
   {
       sil++;
       cinum-=n;

   }

   sih=inum-(sil-1)*n;
   if(sil%2==0)
   {
       sih=n-inum%n+1;
       while(sih>n)
       {
           sih-=n;
       }
   }
   cout<<sil<<" "<<sih;
    return 0;
}
