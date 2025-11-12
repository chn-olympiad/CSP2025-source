#include<iostream>
using namespace std;
int x,y,a[1005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        for(int j=2;j<=y;j++){
            cin>>a[i][j];
        }
    }
    return 0;
}