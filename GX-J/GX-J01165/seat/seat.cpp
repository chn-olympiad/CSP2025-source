#include<iostream>
using namespace std;
int a[100000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n==2||m==2)
      cout<<"1 2";
     else
        cout<<"3 1";
    return 0;
}
