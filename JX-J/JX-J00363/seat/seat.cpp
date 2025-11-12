#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,grade,seat=1,seat1=1,c,b;
    cin>>n>>m;
    int map[10][10],a[100];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    grade=a[0];
    for(int i=0;i<n*m;i++)
    {
        for(int j=0;j<n*m;j++)
        {
            int t;
            if(a[i]>a[j])
            {
                t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
        }
    }
    for(int i=0;i<n*m;i++)
    {
        if(grade==a[i])
        {
            seat=i+1;
        }
    }
    int i=1,j=1;
    b=1;
    c=1;
    while(seat1!=seat)
    {
        if(j%2==1)
        {
            if(i==m)
            {
                b++;j++;
                seat1++;
            }
            else
            {
                c++;i++;
                seat1++;
            }
        }

        else if(j%2==0)
        {
            if(i==1)
            {
                b++;j++;
                seat1++;
            }
            else
            {
                c--;i--;
                seat1++;
            }
        }

    }
    cout<<b<<" "<<c;
    return 0;

}
