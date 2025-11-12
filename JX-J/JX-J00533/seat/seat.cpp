#include<bits/stdc++.h>
using namespace std;
//n行m列
//Sn:第1列第n行
//Sn+1:第2列第n行
//S2n:第2列第1行
////Sn+1:第3列第1行
int n,m;
int y;
int a[20];
int w;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        w=a[1];
    }   
    
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++)
    {
        if(a[i]==w)
        {
            y=i;
        }
        if(y<=2*n+1)
        {
            if(y<=n)
            {
                cout<<1<<" "<<n;
                return 0;
            }
            else if(y==n+1)
            {
                cout<<2<<" "<<2;
               return 0;
            }
            else if(y==2*n)
            {
                cout<<2<<" "<<n;
               return 0;
            }
            else if(y==2*n+1)
            {
                cout<<3<<" "<<1;
                return 0;
            }
        }
        else
        {
           if(y-2*n+1<=n)
           {
               cout<<y/(2*n)<<" "<<y/(n*2)-1;
             return 0;
           }
           else if(y-2*n+1>=n+1 && y-2*n+1<=n+(y-2*n+1))
           {
               cout<<y/(2*n)+1<<" "<<(y%(n*2)-1);
              return 0;
           }
           else if(y-2*n==2*n)
           {
               cout<<y/(2*n)+2<<" "<<1;
               return 0;
           }
        }
        
    }




    return 0;
}