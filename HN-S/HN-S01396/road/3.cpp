#include<bits/stdc++.h>
#include<sys/time.h>
using namespace std;
int main()
{
    freopen("1.in","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    timeval T;
    gettimeofday(&T,NULL);
    mt19937 rd(T.tv_sec*1000000+T.tv_usec);
    int n=1e4,m=1e6,k=10,v=1e9;
    cout<<n<<' '<<m<<' '<<k<<'\n';
    for(int i=1;i<n;i++) cout<<rd()%i+1<<' '<<i+1<<' '<<rd()%v+1<<'\n';
    for(int i=1;i<=m-(n-1);)
    {
        int x=rd()%n+1,y=rd()%n+1;
        if(x==y) continue;
        cout<<x<<' '<<y<<' '<<rd()%v+1<<'\n';
        i++;
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=n;j++) cout<<rd()%v+1<<' ';
        cout<<'\n';
    }
    return 0;
}