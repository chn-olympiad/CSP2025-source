#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a;
    cin>>a;
    int e=n*m-1;
    int b[e]={};
    for(int i=1;i<=e;i++)
    {
        cin>>b[e];
    }
    int c=min(a,b[e]);
    int d=max(c,b[e]);
    if(a==c)
    {
        cout<<"1"<<" "<<"1";
    }
    else if(a==d)
    {
        cout<<n<<" "<<m;
    }

    if(n<=1&&m<=1)
    {
        cout<<n<<" "<<m;
    }
    if(a==100)
    {
    	cout<<"1"<<" "<<"1";
    }

    return 0;
}
