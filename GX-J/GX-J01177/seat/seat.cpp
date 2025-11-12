#include <iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,maxn=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            cin>>x;
            if(x>maxn){
                maxn=i;
            }
        }
    }
    cout<<maxn;
    return 0;
}
