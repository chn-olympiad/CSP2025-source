#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m]={0};
    for(int i=0;i<n*m;i++) cin>>a[i];
    int R=a[0];
    sort(a,a+n*m,greater<int>());
    int cnt=0;
    for(int x=0;x<m;x++)
    {
        int y=x&1?n-1:0;
        while(y<n&&y>=0)
        {
            if(a[cnt]==R)
            {
                cout<<x+1<<' '<<y+1<<endl;
                return 0;
            }
            cnt++;
            y+=x&1?-1:1;
        }
    }
    return 0;
}
