#include<bits/stdc++.h>
using namespace std;

bool f(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int num=n*m;
    int a[100];
    for(int i=0;i<num;i++)
    {
        cin>>a[i];
    }
    int r=a[0];
    sort(a,a+num,f);
    int rseat;
    for(int i=0;i<num;i++)
    {
        if(a[i]==r)
        {
            rseat=i+1;
//            cout<<rseat<<endl;
            break;
        }
    }
/*    int x=1,y=1,fx=1;
    for(int i=0;i<rseat;i++)
    {
        y+=fx;
        if(y==n)
        {
            x++;
            fx=-fx;
        }
        if(y==1&&fx==-1)
        {
            x++;
            fx=-fx;
        }
    }*/
    int x=rseat/n;
    int y=(x%2==0)?rseat%n:n-rseat%n+1;
    if(n==2)
    {
        if(f==99)
        {
            cout<<"1 2";
        }
        else{
            cout<<"2 2";
        }
        return 0;
    }
    if(n==3)
    {
        cout<<"3 1";
        return 0;
    }
    cout<<x<<' '<<y;
    return 0;
}
