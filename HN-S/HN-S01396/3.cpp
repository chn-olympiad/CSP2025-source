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
    int n=1e3,q=1e3,v=3;
    cout<<n<<' '<<q<<'\n';
    for(int i=1;i<=n;i++) 
    {
        int m=rd()%3+1;
        cout<<m<<'\n';
        for(int j=1;j<=m;j++) cout<<(char)(rd()%v+'a');
        cout<<'\n';
        for(int j=1;j<=m;j++) cout<<(char)(rd()%v+'a');
        cout<<'\n';
    }
    while(q--)
    {
        int m=rd()%10+1;
        cout<<m<<'\n';
        for(int j=1;j<=m;j++) cout<<(char)(rd()%v+'a');
        cout<<'\n';
        for(int j=1;j<=m;j++) cout<<(char)(rd()%v+'a');
        cout<<'\n';
    }
    return 0;
}