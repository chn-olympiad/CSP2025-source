#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m;
struct node
{
    int f,p;
}point[200];
bool cmp(node x,node y)
{
    if(x.f<y.f) return false;
    else return true;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++)
    {
        cin >> point[i].f;
        if(i==1)
            point[i].p=-1;
        else
            point[i].p=1;
    }
    sort(point+1,point+1+n*m,cmp);
    int i;
    for(i=1;point[i].p!=-1;i++)
    {/*     */}
    int v=ceil(double(i)/double(n)) ;
    cout << v << " ";
    int y=i%n;
    if(v%2==1) cout <<y;
    else cout << n-y+1;
    return 0;
}
