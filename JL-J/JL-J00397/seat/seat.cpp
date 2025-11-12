#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e6+7;
int n,m;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int R=a[0];
    for(int i=0;i<n*m;i++)
    {
        for(int j=i+1;j<n*m;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    int Ri=0;
    for(int i=0;i<n*m;i++)
    {
        //cout<<a[i]<<" ";
        if(a[i]==R) Ri=i+1;
    }
    //cout<<endl;
    //cout<<R<<" "<<Ri<<" ";
    int r,c;
    if(Ri==m)
        c=Ri/m;
    else if(m==1)
        c=1;
    else
        c=Ri/m+1;
    cout<<c<<" ";
    if(c%2==0&&Ri%n!=0)
        r=(n+1)-(Ri%n);
    else if(Ri%n!=0&&c%2!=0)
        r=Ri%n;
    else if(Ri%n==0&&c%2==0)
        r=1;
    else if(Ri%n==0&&c%2!=0)
        r=n;
    else if(n==1)
        r=1;
    cout<<r;
    return 0;
}
