#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cj;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    cj=a[1];
    sort(a+1,a+n*m+1,[](const int& x,const int& y){return x>y;});
    for(int x=1,now=1;x<=m;x++)
    {
        bool down=x&1;
        for(int y=(down?1:n);(down?y<=n:y>=1);y+=(down?1:-1))
        {
            if(a[now]==cj)
            {
                cout<<x<<' '<<y;
                return 0;
            }
            now++;
        }
    }
    return 0;
}
