#include <iostream>
using namespace std;
int a[105];
int main()
{
    freopen(seat.in,"r",stdout);
    freopen(seat.out,"w",stdout);
    int m,n;
    cin >> n >> m;
    for (int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    int s=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=n*m;j>=1;j--)
        {
            if(a[j]>a[j-1]){
                int p=a[j];
                a[j]=a[j-1];
                a[j-1]=p;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            int u=i;
            break;
        }
    }
    int o[15][15];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            o[i][j]=a[i*j];
            if(a[i*j]==s){
                cout << i << " " << j;
                return 0;
            }
        }
    }
    return 0;
}
