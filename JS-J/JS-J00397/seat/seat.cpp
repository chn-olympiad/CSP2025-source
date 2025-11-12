#include<bits/stdc++.h>
using namespace std;
int n,m;
int r,k;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m>>r;
    k=1;
    int t;
    for(int i=2;i<=n*m;i++)
    {
        cin>>t;
        if(t>r)
            k++;
    }
    int x1=k%(n*2);
    int x2=k/(n*2)+(x1!=0);
    if(x1==0)
        cout<<2*x2<<" "<<1<<endl;
    else if(1<=x1&&x1<=n)
        cout<<2*x2-1<<" "<<x1<<endl;
    else
        cout<<2*x2<<" "<<2*n-x1+1<<endl;
    return 0;
}
