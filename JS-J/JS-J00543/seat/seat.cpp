#include<bits/stdc++.h>
using namespace std;
int a[159],v[159];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    r = a[1];
    sort(a+1,a+1+n*m);
    for(int i = 1;i<=n*m;i++)
    {
        v[i] = a[n*m-i+1];
    }
    /*for(int i =1;i<=n*m;i++)
    {
        printf("%d ",v[i]);
    }*/
    /*for(int i = 1;i<=n*m;i++)
    {
        printf("%d ",a[i]);
    }*/
    int x = 0;
    int cnt = 0;
    for(int i = 1;i<=m;i++)
    {
        if(i%2==1)
        {
            x = 0;
            while(x<n)
            {
                x++;
                cnt++;
                if(v[cnt]==r)
                {
                    printf("%d %d",i,x);
                }
               // printf("%d %d %d\n",i,x,v[cnt]);
            }
        }else{
            x = n+1;
            while(x>1)
            {
                x--;
                cnt++;
                if(v[cnt]==r)
                {
                    printf("%d %d",i,x);
                }
                //printf("%d %d %d\n",i,x,v[cnt]);
            }
        }
    }
  //  printf("\n%d",cnt);
    return 0;
}
