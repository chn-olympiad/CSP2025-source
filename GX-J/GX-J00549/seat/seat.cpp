#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool px(long long x,long long y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long r,n,m,a[10000]={0},way,x=1,y=1,flag=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+n*m+1,px);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==r)
        {
            way=i;
            break;
        }

    }
            way-=1;
            while(way)
            {
                if(flag)
                {
                    if(x==1)
                    {
                        y++;
                        flag=0;
                        way--;
                    }

                    else
                    {
                        x--;
                        way--;
                    }

                }
                else
                {
                    if(x==n)
                    {
                        y++;
                        flag=1;
                        way--;
                    }
                    else
                    {
                        x++;
                        way--;
                    }


                }
            }
            cout<<y<<" "<<x<<endl;





    return 0;
}
