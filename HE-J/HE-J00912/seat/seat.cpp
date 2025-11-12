#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,a[maxn];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    int t=a[1],tt;
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=n*m;i++) if(a[i]==t) tt=i;
    int t1=tt%(2*n),t2=tt/(2*n);
    if(t1==0) t1=2*n;
    if(t1<=n)
    {
        cout<<t2*2+1<<' '<<t1;
    }
    else
    {
        cout<<t2*2+2<<' '<<2*n-t1+1;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
