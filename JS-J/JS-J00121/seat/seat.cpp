#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],score;
bool cmp(int number1,int number2)
{
    return number1>number2;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    score=a[1];
    sort(a+1,a+n*m+1,cmp);
    int x=1,y=1,s=1;
    while(1)
    {
        if(a[s]==score)
        {
            cout<<y<<' '<<x<<endl;
            break;
        }
        s+=1;
        if(y%2==1&&x==n)
        {
            y+=1;
        }
        else if(y%2==0&&x==n)
        {
            x-=1;
        }
        else if(y%2==0&&x==1)
        {
            y+=1;
        }
        else if(y%2==1&&x==1)
        {
            x+=1;
        }
        else if(y%2==1)
        {
            x+=1;
        }
        else if(y%2==0)
        {
            x-=1;
        }
    }
    return 0;
}
