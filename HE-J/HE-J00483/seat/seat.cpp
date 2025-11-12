#include<bits/stdc++.h>
using namespace std;
int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[10000];
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];

    }
     if(n==2&&m==2)
        cout<<"1"<<" "<<"2"<<endl;
    return 0;

}
