#include <bits/stdc++.h>
using namespace std;

int u[100000];
int main()
{
    freopen("seat.in","r",stdin)
	freopen("seat.out","w",stdout)
    int b=0,a,n,m,s=0,l,h=0,x;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>u[i];
    }

    for(int i=0;i<n*m;i++)
    {
        if(max(u[1],u[i])!=u[1])
        {

            u[i]=-1;
            h++;
        }

    }
    x=h+1;
    l=x/n;
    if(l*n!=x)
    {
        l+=1;
    }
    cout<<l<<endl;
    cout<<x%n+1;
    return 0;
}
