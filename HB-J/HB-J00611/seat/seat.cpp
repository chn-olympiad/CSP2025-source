#include<bits/stdc++.h>
using namespace std;
int n,m;
int fe[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<(n*m);i++)
    {
        cin>>fe[i];
    }
    int a=fe[0];sort(fe,fe+(m*n));int x=1,y=1,p=m*n-1;
    if(fe[p]==a)
    {
        cout<<1<<" "<<1;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    while(x<=m&&y<=n)
    {
       for(int i=0;i<=n-2;i++)
       {
       p-=1;y+=1;
           if(fe[p]==a)
           {
              cout<<x<<"  "<<y;
              fclose(stdin);
    fclose(stdout);
              return 0;
           }
       }
      p-=1; x+=1;
        if(fe[p]==a)
           {
           cout<<x<<"  "<<y;
           fclose(stdin);
    fclose(stdout);
           return 0;
           }
       for(int i=0;i<=n-2;i++)
       {
       p-=1;y-=1;
       if(fe[p]==a)
       {
           cout<<x<<"  "<<y;
           fclose(stdin);
    fclose(stdout);
           return 0;
       }
       }
       p-=1;x+=1;
           if(fe[p]==a)
           {
           cout<<x<<"  "<<y;
           fclose(stdin);
           fclose(stdout);
           return 0;
           }
    }
}
