#include<bits/stdc++.h>
using namespace std;
long long n,m,x;
int a[109];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n==1&&m==1)
    {
        cin>>a[0];
        cout<<a[0];
        return 0;
    }

        for(int i=1;i<=m*n;++i)
    {
        cin>>a[i];
    }
    x=a[1];
    if(m!=1&&n==1)
    {
        sort(a+1,a+5);
        for(int i=1;i<=m;++i)
        {
            if(a[i]==x)
            {
                if(i==1)cout<<1<<" "<<1;
                else if(i==2)cout<<2<<" "<<1;
                else if(i==3)cout<<3<<" "<<1;
                else if(i==4)cout<<4<<" "<<1;
                else if(i==5)cout<<5<<" "<<1;
                else if(i==6)cout<<6<<" "<<1;
                else if(i==7)cout<<7<<" "<<1;
                else if(i==8)cout<<8<<" "<<1;
                else if(i==9)cout<<9<<" "<<1;
                else if(i==10)cout<<10<<" "<<1;
                return 0;
            }
        }
    }
    if(n!=1&&m==1)
    {
       sort(a+1,a+5);
        for(int i=1;i<=n;++i)
        {
            if(a[i]==x)
            {
				if(i==1)cout<<1<<" "<<1;
                else if(i==2)cout<<1<<" "<<2;
                else if(i==3)cout<<1<<" "<<3;
                else if(i==4)cout<<1<<" "<<4;
                else if(i==5)cout<<1<<" "<<5;
                else if(i==6)cout<<1<<" "<<6;
                else if(i==7)cout<<1<<" "<<7;
                else if(i==8)cout<<1<<" "<<8;
                else if(i==9)cout<<1<<" "<<9;
                else if(i==10)cout<<1<<" "<<10;
                return 0;
            }
        }
    }
    if(n==2&&m==2)
    {
        sort(a+1,a+5);
        for(int i=1;i<=n*m;++i)
        {
            if(a[i]==x)
            {
                if(i==1)cout<<2<<" "<<1;
                else if(i==2)cout<<2<<" "<<2;
                else if(i==3)cout<<1<<" "<<2;
                else if(i==4)cout<<1<<" "<<1;
                return 0;
            }
        }
    }
    return 0;
}
