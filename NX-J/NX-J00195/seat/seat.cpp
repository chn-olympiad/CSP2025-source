#include<bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("seat.in","r",stdin);
//    freopen("seat .out","w",stdout);
    int m,n,r,s=0,x;
    cin>>m>>n>>r;
    for(int i=1;i<m*n;i++)
    {
        cin>>x;
        if(x>r)
        {
            s++;
        }
    }
    cout<<s/m+1<<' '<<s%m+1;

    return 0;
}
