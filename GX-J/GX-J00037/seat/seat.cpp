#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;

int n,m,a[N*N],pos;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    int pos = a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++)
    {
        if(pos == a[i])
        {
            int lie = (i+n-1)/n;
            int hang = i%n;
            if(hang==0) hang = n;
            if(lie%2==0) hang = n-hang+1;
            printf("%d %d",lie,hang);
            break;
        }
    }
    return 0;
}
