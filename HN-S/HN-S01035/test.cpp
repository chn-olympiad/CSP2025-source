#include<bits/stdc++.h>
using namespace std;
map<int,int> mp[100005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    srand(random_device{}());
    int n=10000,m=1000000,k=10,V=1000000000;
    cout<<n<<' '<<m<<' '<<k<<'\n';
    for(int i=1;i<n;i++) cout<<i<<' '<<i+1<<' '<<rand()%V+1<<'\n';
    for(int i=n;i<=m;i++)
    {
        int x=rand()%n+1,y=rand()%n+1;
        if(x==y) {i--; continue;}
        if(mp[x][y]||mp[y][x]) {i--; continue;}
        mp[x][y]=1; cout<<x<<' '<<y<<' '<<rand()%V+1<<'\n';
    }
    for(int i=1;i<=k;i++,cout<<'\n')
        for(int j=1;j<=n+1;j++)
            cout<<rand()%V+1<<' ';
}