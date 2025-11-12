#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char a[15][15];
int b[225];
int main()
{
    int c;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x=0;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> b[i];
        c=b[1];
    }
    sort(b,b+n*m+1);
    for(int s=1;s<=m;s++)
    {
     if(m%2==0)
      {
          for(int j=m;j>=1;j--){
         for(int i=1;i<=n;i++)
         {
             x++;
             a[i][j]=b[x];
             if(a[i][j]==c)
             {
                 cout << j<<" "<<i;
                 return 0;
             }
         }
         m--;
         break;}


      }
     if(m%2==1)
     {
         for(int j=m;j>=1;j--){

         for(int i=n;i>=1;i--)
         {
             x++;
             a[i][j]=b[x];
             if(a[i][j]==c)
             {
                 cout << j<<" "<<i;
                 return 0;
             }
         }
         m--;
         break;}

    }
    }



    return 0;
}


